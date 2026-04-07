#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <Arduino.h>
#include <cstdint>

// Stores the constants and data structures used across the project for better organization and maintainability.

#define WINDOW_SIZE 5
#define QUEUE_LENGTH 5
#define CAN_ID 0x123

struct CANFrame{
    uint8_t errorFlag;
    float filteredValue;
};
#endif // CONSTANTS_H