#ifndef HID_COMM_H
#define HID_COMM_H

#include "quantum.h"

typedef enum {
    AppIntegration      = 1,
    AudioVisualizer     = 2,
    LiveWeather         = 3,
    MessageHandler      = 4,
    NotificationHandler = 5,
    ServerHandler       = 6,
    StateHandler        = 7
} ComponentId;


void hid_handle(uint8_t *data, uint8_t length);


#endif // HID_COMM_H
