#ifndef CANTASK_H
#define CANTASK_H

// The canTask is responsible for receiving processed CAN frames from the sensorTask and printing the results to the Serial monitor. It runs in an infinite loop, waiting for new CAN frames to arrive in the queue, and then it prints the raw sensor value, the filtered value, and any error flags associated with the data.

void canTask(void *pvParameters);

#endif // CANTASK_H