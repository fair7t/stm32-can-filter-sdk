# Quick start
1. Скачайте релиз и положите `lib/libcanfilter_core.a` в проект.
2. Подключите `include/canfilter.h`.
3. В `main()` вызовите `cf_init(cfg, len)` и в RX callback вызывайте `cf_process(in, out, &dir)`.
4. Отправляйте кадр `out` на нужный CAN-канал (см. `dir`).
