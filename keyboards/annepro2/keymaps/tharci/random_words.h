#pragma once

#include "stdint.h"

typedef enum {
    EFF_WEAVE_GREEN = 0,
    EFF_WEAVE_YELLOW,
    EFF_WEAVE_RED,
    EFF_FLASH_KEY,
    EFF_DISPLAY_NUMBER,
    EFF_BLT_CONN,
    EFF_BLT_BROAD,
} EffectEnum;

void randomWords_update(uint16_t keycode);

