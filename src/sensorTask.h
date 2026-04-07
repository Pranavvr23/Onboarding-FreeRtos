#ifndef SENSORTASK_H
#define SENSORTASK_H

// The sensorTask is responsible for simulating sensor data, applying a moving average filter to the data, and sending the processed data to the canTask via a FreeRTOS queue. It runs in an infinite loop, generating new sensor readings, processing them, and then sending the results to the CAN task for further handling.

void sensorTask(void *pvParameters);

#endif // SENSORTASK_H