# STM32 CAN Filter SDK

Public SDK (headers, docs, examples) for a closed-source STM32 CAN filter.
Core logic remains private and ships as a prebuilt static library (`libcanfilter_core.a`).

## Contents
- `include/canfilter.h` — public API
- `examples/nucleo_f411re/` — CubeIDE-style example
- `docs/` — quick start & config format
- `lib/` — prebuilt library (added by CI from private repo)

## Basic usage
```c
cf_init(cfg, len);
if (cf_process(&in, &out, &dir)) { /* send out */ }
