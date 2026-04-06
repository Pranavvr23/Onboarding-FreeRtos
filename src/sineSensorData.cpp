#include <math.h>
#include "sineSensorData.h"
float sineSensorData() {
    // Simulate sensor data using a sine wave
    static float angle = 0.0;
    float data = (sinf(angle) + 1.0) * 50.0; // Sine wave between 0.0 and 100.0
    angle += 0.1; // Increment angle for next reading
    if (angle > 2 * M_PI) {
        angle -= 2 * M_PI; // Reset angle to prevent overflow
    }
    return data;
}