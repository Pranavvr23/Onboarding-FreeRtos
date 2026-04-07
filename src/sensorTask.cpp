#include <Arduino.h>
#include <FreeRTOS.h>
#include <task.h>
#include <queue.h>

#include "CONSTANTS.h"
#include "sensorTask.h"
#include "randomSensorData.h"
#include "sineSensorData.h"
#include "movingAverage.h"


extern QueueHandle_t canQueue; // Access the global CAN queue
extern float rawValue; // Access the global raw value for debugging purposes
extern float averageValue; // Access the global average value for debugging purposes
void sensorTask(void *pvParameters) {
    // This task would read sensor data and process it
    // For this example, we will just simulate the sensor reading in the main loop
    CANFrame frame;
    for( ; ; ) {
        // Simulate reading sensor data and processing it
        float sample = randomSensorData() + sineSensorData();
        rawValue = sample; // Store the raw value
        float avg = movingAverage(sample); // Apply moving average filter to the sensor data
        averageValue = avg; // Store the moving average value
        frame.errorFlag = (avg < 0.0 || avg > 100.0) ? 1 : 0; // Set error flag if the value is outside the valid range
        if (avg > 100.0) avg = 100.0; // clamp the value to the maximum of 100.0
        if (avg < 0.0) avg = 0.0; // clamp the value to the minimum of 0.0
        frame.filteredValue = (uint16_t)(avg);
        
        xQueueSend(canQueue, &frame, 0); // Send the processed data to the CAN task
        
        vTaskDelay(pdMS_TO_TICKS(100)); // Simulate a delay between sensor readings
    }
}