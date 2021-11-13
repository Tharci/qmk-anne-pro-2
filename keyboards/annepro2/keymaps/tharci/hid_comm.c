#include "hid_comm.h"

#include "led.h"
#include "persistence.h"


typedef enum {
    DriverConnected = 1,
    ComponentMessage = 2,
} MessageType;


typedef enum {
    AppIntegration      = 1,
    AudioVisualizer     = 2,
    LiveWeather         = 3,
    MessageHandler      = 4,
    NotificationHandler = 5,
    ServerHandler       = 6,
    StateHandler        = 7
} ComponentId;


const uint8_t magicalSafetyCode[2] = { 0x32, 0xf3 };


typedef enum {
    CommVersion_V_0_0_1 = 0,
} CommVersion;


void hid_handle(uint8_t* data, uint8_t length) {
    if (length == 0) {
        return;
    }

    if (data[0] != magicalSafetyCode[0] || data[1] != magicalSafetyCode[1]) {
        return;
    }

    if (data[2] == CommVersion_V_0_0_1) {
        if (data[3] == DriverConnected) {
            ledDriverConnected();
        }
        else if (data[3] == ComponentMessage) {
            if (data[4] == LiveWeather) {
                ledSetWeather(data + 5, length - 5);
            }
            else {
                return;
            }
        }
        else {
            return;
        }
    }
    else {
        return;
    }
}


