#include "randomSensorData.h"
#include <math.h>

float randomSensorData() {
    // Simulate sensor data
    float data = (float)(rand() % 40) - 20.0; // Random value between -20.0 and 20.0
    return data; 
}