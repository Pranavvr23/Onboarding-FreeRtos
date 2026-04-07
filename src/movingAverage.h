#ifndef MOVING_AVERAGE_H
#define MOVING_AVERAGE_H

// The movingAverage function implements a simple moving average filter to smooth out the sensor data. It maintains a buffer of the most recent sensor readings and calculates the average of these readings to provide a filtered value that is less susceptible to noise.

float movingAverage(float newValue);

#endif // MOVING_AVERAGE_H