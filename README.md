In this project, I have implemented a simple simulated FreeRTOS environment. The program creates a virtual sensor with random noise and the data from that sensor is then transmitted over a CAN Frame. The data from this frame is then printed to the serial monitor in a readable format.

To compile and run the FreeRTOS program, the user must have VS Code and the PlatformIO extension installed. Next, make sure to set the board to teensy and the framework to arduino. Additionally, the user will have to include the FreeRTOS teensy library in the platformio.ini file using lib_deps= (this can be found in my platform.ini file). It is important to note that the Free RTOS doesn't use the loop() function in the arduino framework and instead has its own built in process to run the tasks.

The CAN layout is organized as the following: Bytes 0–1 store the filtered value, and Byte 2 stores the error flag.

If an error is present, that means that the data from the virtual sensor has a value below 0 or above 100.

Below I have attatched a screenshot of the program's output
<img width="855" height="387" alt="Screenshot 2026-04-07 122546" src="https://github.com/user-attachments/assets/edb42095-ffc7-466c-bc44-072a52637e99" />
.
