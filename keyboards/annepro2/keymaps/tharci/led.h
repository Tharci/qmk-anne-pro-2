#pragma once

#include "annepro2.h"
#include "persistence.h"
#include "random_words.h"

typedef enum {           // Messages:
    LED_TOGGLE = 1,         // 1 byte: 0 - off, 1 - on
    LED_NEXT_PROFILE,       // 0 byte
    LED_PREV_PROFILE,       // 0 byte
    LED_SET_PROFILE,        // 1 byte: profile
    LED_GET_PROFILE,        // 0 byte; response - 1 byte: message
    LED_GET_PROFILE_COUNT,  // 0 byte; response - 1 byte: message
    LED_KEY_PRESSED,        // 1 byte: col (4 bits) + row (4 bits)
    LED_CAPS_ON,            // 0 byte
    LED_CAPS_OFF,           // 0 byte
    LED_BLT_CONNECTING,     // 1 byte: 1-4
    LED_BLT_CONNECTED,      // 0 byte
    LED_BRIGHT_DOWN,        // 0 byte
    LED_BRIGHT_UP,          // 0 byte
    LED_SET_BRIGHT,         // 1 byte: brightness (0-100)
    LED_GET_BRIGHT,
    LED_GAMING_ON,
    LED_GAMING_OFF,
    LED_SET_LOCKED,
    LED_IAP_MODE,
    LED_SET_POWER_PLAN,     // 1 byte; 0 - battery, 1 - usb, 2 - max
    LED_UPDATE_WEATHER,
    LED_SHOW_TEMP,
    LED_SHOW_TIME,
    LED_MAIN_INIT_DONE,
    LED_DRIVER_CONNECTED,
    LED_SET_LAYER,          // 1 byte: layer
    LED_AUDIO_PACKET,       // 14 bytes
    LED_SET_PROF_STATE,     // 2 bytes: profile, state (1 - 6)
    LED_RANDOM_WORD,        // 1 byte: effect
} LedMsgCode;


void led_init(void);
void ledToggle(void);
void ledSetProfile(uint8_t prof);
uint8_t ledGetProfile(void);
uint8_t ledGetNumProfiles(void);
void ledNextProfile(void);
void ledKeyPressed(uint8_t keyPos);
void ledBrightDown(void);
void ledBrightUp(void);
void ledCapsOn(void);
void ledCapsOff(void);
void ledSetBrightness(uint8_t brightness);
uint8_t ledGetBrightness(void);
void ledGamingOn(void);
void ledGamingOff(void);
void ledBleConnecting(uint8_t port);
void ledBleConnected(void);
void ledSetLocked(bool isLocked);
void ledGoIntoIAP(void);
void ledSetPowerPlan(PowerPlan powerPlan);
void ledSetWeather(uint8_t* data, uint8_t length);
void ledShowTemp(void);
void ledShowTime(void);
void ledMainInitDone(void);
void ledDriverConnected(void);
void ledSetLayer(layer_state_t layer);
void ledAudioPacket(uint8_t* data, uint8_t length);
void ledSetProfileState(uint8_t profile, uint8_t state);
void ledRandomWord(EffectEnum effect);