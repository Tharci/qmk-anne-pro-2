
#include "led.h"
#include "hal.h"
#include "annepro2.h"


static mutex_t led_mutex;

void ledSendMessageCode(LedMsgCode msgCode) {
    // uint8_t data[] = {85, 54, 111, 1, (uint8_t) msgCode};
    // sdWrite(&SD0, data, sizeof(data));
    sdPut(&SD0, msgCode);
}

void led_init() {
    chMtxObjectInit(&led_mutex);
}

void ledToggle(void) {
    chMtxLock(&led_mutex);
    ledSendMessageCode(LED_TOGGLE);
    chMtxUnlock(&led_mutex);
}

void ledSetProfile(uint8_t profile) {
    chMtxLock(&led_mutex);
    ledSendMessageCode(LED_SET_PROFILE);
    sdPut(&SD0, profile);
    chMtxUnlock(&led_mutex);
}

uint8_t ledGetProfile(void) {
    chMtxLock(&led_mutex);
    ledSendMessageCode(LED_GET_PROFILE);
    uint8_t buf = sdGetTimeout(&SD0, 1000);
    chMtxUnlock(&led_mutex);
    
    return buf != MSG_TIMEOUT ? buf : 0;
}

uint8_t ledGetNumProfiles(void) {
    chMtxLock(&led_mutex);
    ledSendMessageCode(LED_GET_PROFILE_COUNT);
    uint8_t profileCount = sdGetTimeout(&SD0, 1000);
    chMtxUnlock(&led_mutex);

    return profileCount != MSG_TIMEOUT ? profileCount : 1;
}

void ledNextProfile(void) {
    chMtxLock(&led_mutex);
    ledSendMessageCode(LED_NEXT_PROFILE);
    chMtxUnlock(&led_mutex);
}

void ledKeyPressed(uint8_t keyPos) {
    chMtxLock(&led_mutex);
    ledSendMessageCode(LED_KEY_PRESSED);
    sdPut(&SD0, keyPos);
    chMtxUnlock(&led_mutex);
}

void ledBrightDown(void) {
    chMtxLock(&led_mutex);
    ledSendMessageCode(LED_BRIGHT_DOWN);
    chMtxUnlock(&led_mutex);
}

void ledBrightUp(void) {
    chMtxLock(&led_mutex);
    ledSendMessageCode(LED_BRIGHT_UP);
    chMtxUnlock(&led_mutex);
}

void ledCapsOn(void) {
    chMtxLock(&led_mutex);
    ledSendMessageCode(LED_CAPS_ON);
    chMtxUnlock(&led_mutex);
}

void ledCapsOff(void) {
    chMtxLock(&led_mutex);
    ledSendMessageCode(LED_CAPS_OFF);
    chMtxUnlock(&led_mutex);
}


void ledSetBrightness(uint8_t brightness) {
    chMtxLock(&led_mutex);
    ledSendMessageCode(LED_SET_BRIGHT);
    sdPut(&SD0, brightness);
    chMtxUnlock(&led_mutex);
}

uint8_t ledGetBrightness(void) {
    chMtxLock(&led_mutex);
    ledSendMessageCode(LED_GET_BRIGHT);
    uint8_t brightness = sdGetTimeout(&SD0, 1000);
    chMtxUnlock(&led_mutex);
    
    return brightness != MSG_TIMEOUT ? brightness : 50;
}

void ledGamingOn(void) {
    chMtxLock(&led_mutex);
    ledSendMessageCode(LED_GAMING_ON);
    chMtxUnlock(&led_mutex);
}

void ledGamingOff(void) {
    chMtxLock(&led_mutex);
    ledSendMessageCode(LED_GAMING_OFF);
    chMtxUnlock(&led_mutex);
}

void ledBleConnecting(uint8_t port) {
    chMtxLock(&led_mutex);
    ledSendMessageCode(LED_BLT_CONNECTING);
    sdPut(&SD0, port);
    chMtxUnlock(&led_mutex);
}

void ledBleConnected(void) {
    chMtxLock(&led_mutex);
    ledSendMessageCode(LED_BLT_CONNECTED);
    chMtxUnlock(&led_mutex);
}

void ledSetLocked(bool isLocked) {
    chMtxLock(&led_mutex);
    ledSendMessageCode(LED_SET_LOCKED);
    sdPut(&SD0, isLocked);
    chMtxUnlock(&led_mutex);
}

void ledGoIntoIAP(void) {
    chMtxLock(&led_mutex);
    ledSendMessageCode(LED_IAP_MODE);
    chMtxUnlock(&led_mutex);
}

void ledSetPowerPlan(PowerPlan powerPlan) {
    chMtxLock(&led_mutex);
    ledSendMessageCode(LED_SET_POWER_PLAN);
    sdPut(&SD0, powerPlan);
    chMtxUnlock(&led_mutex);
}

void ledSetWeather(uint8_t* data, uint8_t length) {
    chMtxLock(&led_mutex);
    ledSendMessageCode(LED_UPDATE_WEATHER);
    sdWrite(&SD0, data, length);
    chMtxUnlock(&led_mutex);
}

void ledShowTemp(void) {
    chMtxLock(&led_mutex);
    ledSendMessageCode(LED_SHOW_TEMP);
    chMtxUnlock(&led_mutex);
}

void ledShowTime(void) {
    chMtxLock(&led_mutex);
    ledSendMessageCode(LED_SHOW_TIME);
    chMtxUnlock(&led_mutex);
}

void ledMainInitDone(void) {
    chMtxLock(&led_mutex);
    ledSendMessageCode(LED_MAIN_INIT_DONE);
    chMtxUnlock(&led_mutex);
}

void ledDriverConnected(void) {
    chMtxLock(&led_mutex);
    ledSendMessageCode(LED_DRIVER_CONNECTED);
    chMtxUnlock(&led_mutex);
}

void ledSetLayer(layer_state_t layer) {
    chMtxLock(&led_mutex);
    ledSendMessageCode(LED_SET_LAYER);
    sdPut(&SD0, layer);
    chMtxUnlock(&led_mutex);
}

void ledAudioPacket(uint8_t* data, uint8_t length) {
    chMtxLock(&led_mutex);
    ledSendMessageCode(LED_AUDIO_PACKET);
    sdWrite(&SD0, data, length);
    chMtxUnlock(&led_mutex);
}
