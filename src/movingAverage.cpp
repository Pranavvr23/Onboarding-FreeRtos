#include "movingAverage.h"
#include "CONSTANTS.h"


float movingAverage(float newValue) {

    static float sum = 0.0;
    static float prevVals[WINDOW_SIZE] = {0}; // create a static array to hold previous values sampled from the sensor
    static int index = 0;
    static int count = 0;

    sum -= prevVals[index]; // subtract the value that is being replaced from the sum
    sum += newValue; // add the new value to the sum
    prevVals[index] = newValue; // replace or add the new value into the array at the current index
    index = (index + 1) % WINDOW_SIZE; // increment the current index, and if it exceeds the window size, loop back to 0th index
    if(count < WINDOW_SIZE) { // count cannot exceed the window size
        count++;
    }
    
    return sum/count;
}