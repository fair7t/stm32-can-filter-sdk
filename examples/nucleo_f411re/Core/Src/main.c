#include "main.h"
#include "can.h"          // сгенерируй CubeMX
#include "canfilter.h"
#include <string.h>

extern CAN_HandleTypeDef hcan1;
extern CAN_HandleTypeDef hcan2;

static inline void rx_to_cf(const CAN_RxHeaderTypeDef* r, const uint8_t* d, cf_frame_t* f){
  f->ide = (r->IDE == CAN_ID_EXT);
  f->rtr = (r->RTR == CAN_RTR_REMOTE);
  f->id  = f->ide ? r->ExtId : r->StdId;
  f->dlc = (r->DLC > 8) ? 8 : r->DLC;
  for(uint8_t i=0;i<f->dlc;i++) f->data[i]=d[i];
}

static inline void cf_to_tx(const cf_frame_t* f, CAN_TxHeaderTypeDef* t, uint8_t* d){
  memset(t,0,sizeof(*t));
  if(f->ide){ t->IDE=CAN_ID_EXT; t->ExtId=f->id; } else { t->IDE=CAN_ID_STD; t->StdId=f->id; }
  t->RTR = f->rtr ? CAN_RTR_REMOTE : CAN_RTR_DATA;
  t->DLC = (f->dlc>8)?8:f->dlc;
  for(uint8_t i=0;i<t->DLC;i++) d[i]=f->data[i];
}

void app_init(void){
  // UID F4 можно читать из HAL/регистров; для примера передаём NULL
  static const uint8_t cfg_blob[] = {1,0,0,0};
  // cf_bind_uid(uid_ptr);
  cf_init(cfg_blob, sizeof(cfg_blob));
}

void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan){
  CAN_RxHeaderTypeDef rh; uint8_t rd[8];
  if(HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0, &rh, rd)!=HAL_OK) return;

  cf_frame_t in,out; cf_dir_t dir;
  rx_to_cf(&rh, rd, &in);

  if(cf_process(&in,&out,&dir)){
    CAN_TxHeaderTypeDef th; uint8_t td[8]; uint32_t mbx;
    cf_to_tx(&out,&th,td);

    CAN_HandleTypeDef* target =
      (dir==CF_DIR_TO_CAN1)? &hcan1 :
      (dir==CF_DIR_TO_CAN2)? &hcan2 :
      ((hcan==&hcan1)? &hcan2 : &hcan1);

    HAL_CAN_AddTxMessage(target, &th, td, &mbx);
  }
}
