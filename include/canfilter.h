#pragma once
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { CF_OK=0, CF_ERR=-1, CF_ERR_LICENSE=-2 } cf_status_t;

typedef struct {
  uint32_t id;
  uint8_t  ide;   // 0=std, 1=ext
  uint8_t  rtr;   // 0=data, 1=rtr
  uint8_t  dlc;   // 0..8
  uint8_t  data[8];
} cf_frame_t;

typedef enum { CF_DIR_SAME=0, CF_DIR_TO_CAN1=1, CF_DIR_TO_CAN2=2 } cf_dir_t;

cf_status_t cf_init(const uint8_t* cfg, uint32_t len);
int  cf_process(const cf_frame_t* in, cf_frame_t* out, cf_dir_t* dir);
cf_status_t cf_bind_uid(const uint8_t uid96[12]);

#ifdef __cplusplus
}
#endif
