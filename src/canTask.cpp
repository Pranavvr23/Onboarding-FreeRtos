#include <Arduino.h>
#include <FreeRTOS.h>
#include <task.h>
#include <queue.h>
#include "canTask.h"
#include "CONSTANTS.h"

extern QueueHandle_t canQueue; // Access the global CAN queue
void canTask(void *pvParameters) {
    CANFrame frame;
    for( ; ; ) {
        if (xQueueReceive(canQueue, &frame, portMAX_DELAY) == pdTRUE) {
            Serial.print("CAN[ID=0x");
            Serial.print(CAN_ID, HEX);
            Serial.print("]: ");
            Serial.print(frame.filteredValue);
            Serial.print("%, ");
            Serial.println(frame.errorFlag ? "Error" : "OK");
        }
    }
}