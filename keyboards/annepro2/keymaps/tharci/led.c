
#include "led.h"
#include "hal.h"
#include "annepro2.h"


void ledSendMessageCode(LedMsgCode msgCode) {
    // uint8_t data[] = {85, 54, 111, 1, (uint8_t) msgCode};
    // sdWrite(&SD0, data, sizeof(data));
    sdPut(&SD0, msgCode);
}

void led_init() {
    
}

void ledToggle(void) {
    ledSendMessageCode(LED_TOGGLE);
}

void ledSetProfile(uint8_t profile) {
    ledSendMessageCode(LED_SET_PROFILE);
    sdPut(&SD0, profile);
}

uint8_t ledGetProfile(void) {
    ledSendMessageCode(LED_GET_PROFILE);
    uint8_t buf = sdGetTimeout(&SD0, 1000);
    
    return buf != MSG_TIMEOUT ? buf : 0;
}

uint8_t ledGetNumProfiles(void) {
    ledSendMessageCode(LED_GET_PROFILE_COUNT);
    uint8_t profileCount = sdGetTimeout(&SD0, 1000);

    return profileCount != MSG_TIMEOUT ? profileCount : 1;
}

void ledNextProfile(void) {
    ledSendMessageCode(LED_NEXT_PROFILE);
}

void ledKeyPressed(uint8_t keyPos) {
    ledSendMessageCode(LED_KEY_PRESSED);
    sdPut(&SD0, keyPos);
}

void ledBrightDown(void) {
    ledSendMessageCode(LED_BRIGHT_DOWN);
}

void ledBrightUp(void) {
    ledSendMessageCode(LED_BRIGHT_UP);
}

void ledCapsOn(void) {
    ledSendMessageCode(LED_CAPS_ON);
}

void ledCapsOff(void) {
    ledSendMessageCode(LED_CAPS_OFF);
}


void ledSetBrightness(uint8_t brightness) {
    ledSendMessageCode(LED_SET_BRIGHT);
    sdPut(&SD0, brightness);
}

uint8_t ledGetBrightness(void) {
    ledSendMessageCode(LED_GET_BRIGHT);
    uint8_t brightness = sdGetTimeout(&SD0, 1000);

    return brightness != MSG_TIMEOUT ? brightness : 50;
}

void ledGamingOn(void) {
    ledSendMessageCode(LED_GAMING_ON);
}

void ledGamingOff(void) {
    ledSendMessageCode(LED_GAMING_OFF);
}

void ledBleConnecting(uint8_t port) {
    ledSendMessageCode(LED_BLT_CONNECTING);
    sdPut(&SD0, port);
}

void ledBleConnected(void) {
    ledSendMessageCode(LED_BLT_CONNECTED);
}

void ledSetLocked(bool isLocked) {
    ledSendMessageCode(LED_SET_LOCKED);
    sdPut(&SD0, isLocked);
}

void ledGoIntoIAP(void) {
    ledSendMessageCode(LED_IAP_MODE);
}

void ledSetPowerPlan(PowerPlan powerPlan) {
    ledSendMessageCode(LED_SET_POWER_PLAN);
    sdPut(&SD0, powerPlan);
}

void ledSetWeather(uint8_t* data, uint8_t length) {
    ledSendMessageCode(LED_UPDATE_WEATHER);
    sdWrite(&SD0, data, length);
}

void ledShowTemp(void) {
    ledSendMessageCode(LED_SHOW_TEMP);
}

void ledShowTime(void) {
    ledSendMessageCode(LED_SHOW_TIME);
}

void ledMainInitDone(void) {
    ledSendMessageCode(LED_MAIN_INIT_DONE);
}

void ledDriverConnected(void) {
    ledSendMessageCode(LED_DRIVER_CONNECTED);
}

void ledSetLayer(layer_state_t layer) {
    ledSendMessageCode(LED_SET_LAYER);
    sdPut(&SD0, layer);
}

void ledAudioPacket(uint8_t* data, uint8_t length) {
    ledSendMessageCode(LED_AUDIO_PACKET);
    sdWrite(&SD0, data, length);
}


void ledSetProfileState(uint8_t profile, uint8_t state) {
    ledSendMessageCode(LED_SET_PROF_STATE);
    sdPut(&SD0, profile);
    sdPut(&SD0, state);
}