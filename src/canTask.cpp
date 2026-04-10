#include <Arduino.h>
#include <FreeRTOS.h>
#include <task.h>
#include <queue.h>
#include "canTask.h"
#include "CONSTANTS.h"

extern QueueHandle_t canQueue; // Access the global CAN queue
float rawValue = 0.0; // Global variable to store the raw sensor value for debugging purposes
void canTask(void *pvParameters) {
    CANFrame frame;
    for( ; ; ) {
        if (xQueueReceive(canQueue, &frame, portMAX_DELAY) == pdTRUE) {
            Serial.print("CAN Frame >> ");
            Serial.print("CAN ID: 0x"); // print the CAN ID in hexadecimal format
            Serial.print((uint32_t)frame.id & 0xFFFFFF, HEX); // print the error flag in hexadecimal format
            Serial.print(", Raw Value: "); // print raw value before any filtering
            Serial.print(rawValue);
            Serial.print(", Filtered Value: "); // print the filtered value 
            Serial.print(frame.filteredValue);
            Serial.print("%, ");
            Serial.print("Error Flag: ");
            Serial.println((frame.errorFlag) ? "ERROR" : "OK");
        }
    }
}