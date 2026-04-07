#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <task.h>
#include <queue.h>

#include "CONSTANTS.h"
#include "sensorTask.h"
#include "canTask.h"


QueueHandle_t canQueue; // Access the global CAN queue
void setup() {
  canQueue = xQueueCreate(QUEUE_LENGTH, sizeof(CANFrame)); // Create a queue for CAN frames
    if (canQueue == NULL) {
        Serial.println("Failed to create CAN queue"); // Check if the queue was created successfully
        return;
    }

    xTaskCreate(sensorTask, "Sensor Task", 2048, NULL, 2, NULL); // Create the sensor task which has higher priority than the CAN task to ensure it can read and process sensor data without delay
    xTaskCreate(canTask, "CAN Task", 2048, NULL, 1, NULL); // Create the CAN task which has lower priority than the sensor task to allow it to process CAN frames after the sensor task has read and processed the data

    vTaskStartScheduler(); //start the FreeRTOS scheduler to run the tasks
}

void loop() {
  // The loop function is not used in this FreeRTOS-based program, as the tasks are managed by the FreeRTOS scheduler. However, it must be defined, even if it is empty, to satisfy the Arduino framework requirements.
}


