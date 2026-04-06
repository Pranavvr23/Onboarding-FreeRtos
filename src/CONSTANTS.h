#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <Arduino.h>
#include <cstdint>
#define WINDOW_SIZE 5
#define QUEUE_LENGTH 10
#define CAN_ID 0x123

struct CANFrame{
    uint8_t errorFlag;
    uint16_t filteredValue;
};
#endif // CONSTANTS_H