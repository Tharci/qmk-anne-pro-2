#include "hid_comm.h"

#include "led.h"
#include "persistence.h"
#include "raw_hid.h"

typedef struct __attribute__ ((aligned (4))) {
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
} Time;

typedef struct __attribute__ ((aligned (4))) {
    Time time;
    Time sunriseTime;
    Time sunsetTime;
    int8_t temp;
    int8_t tempMin;
    int8_t tempMax;
    uint8_t sunIntensity;
    uint8_t cloudDensity;
    uint8_t windIntensity;
    uint8_t rainIntensity;
    uint8_t stormIntensity;
    uint8_t snowIntensity;
    bool mist;
} WeatherData;


typedef enum {
    DriverConnected = 1,
    ComponentMessage = 2,
} MessageType;


const uint8_t magicalSafetyCode[2] = { 0x32, 0xf3 };


typedef enum {
    CommVersion_V_0_0_1 = 0,
} CommVersion;


void hid_handle(uint8_t* data, uint8_t length) {
    if (length < 4) {
        return;
    }

    if (data[0] != magicalSafetyCode[0] || data[1] != magicalSafetyCode[1]) {
        return;
    }

    if (data[2] == CommVersion_V_0_0_1) {
        if (data[3] == DriverConnected) {
            ledDriverConnected();
            pers_audioVisUpdate();
        }
        else if (data[3] == ComponentMessage) {
            if (data[4] == LiveWeather) {
                if (length - 5 >= sizeof(WeatherData))
                    ledSetWeather(data + 5, sizeof(WeatherData));
            }
            else if (data[4] == AudioVisualizer) {
                if (length - 5 >= 14)
                    ledAudioPacket(data + 5, 14);
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


