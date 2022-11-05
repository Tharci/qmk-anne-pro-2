#include "random_words.h"
#include "keycode.h"
#include "ch.h"
#include "led.h"


static systime_t sysTimeMs(void) {
    return chTimeI2MS(chVTGetSystemTime());
}

typedef struct {
    uint8_t idx;
    uint16_t word[12 + 1];
    EffectEnum effect;
} Word;

Word words[] = {
    {0, {KC_H, KC_E, KC_L, KC_L, KC_O, KC_SPACE, KC_W, KC_O, KC_R, KC_L, KC_D, 0}, EFF_WEAVE_GREEN},
    {0, {KC_B, KC_R, KC_U, KC_H, 0}, EFF_CIRCLE},
};

static systime_t lastUpdated = 0;
static const systime_t updateTimeoutMs = 1000;

void randomWords_update(uint16_t keycode) {
    systime_t currTime = sysTimeMs();
    if (currTime - lastUpdated > updateTimeoutMs) {
        for (int i = 0; i < sizeof(words) / sizeof(words[0]); i++) {
            words[i].idx = 0;
        }
    }

    lastUpdated = currTime;

    for (int i = 0; i < sizeof(words) / sizeof(words[0]); i++) {
        if (words[i].word[words[i].idx] != keycode) {
            words[i].idx = 0;
        }

        if (words[i].word[words[i].idx] == keycode) {
            words[i].idx++;

            if (words[i].word[words[i].idx] == 0) {
                ledRandomWord(words[i].effect);
                words[i].idx = 0;
            }
        }
        else {
            words[i].idx = 0;
        }
    }
}


