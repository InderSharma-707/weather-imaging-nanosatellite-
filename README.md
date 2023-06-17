# weather-imaging-nanosatellite-
Weather Imaging CubeSat with Telemetry Transmission

Satellites are launched in orbit for a variety of purposes including communication, GPS, Weather imaging and similar applications. 
Weather imaging satellites are used to transmit data about weather parameters that can be used for prediction and forecasting systems.
So here we develop a demo weather imaging and parameter transmission satellite to transmit weather data for analysis back to the earth. 

The satellite delivers following functions:

1.Record and transmit earth weather imaging data
2.Sense and transmit infrared radiation levels to detect solar winds
3.Sense and transmit temperature
4.Self Charge itself using Solar Power

The system makes use of an STM32 controller along with a solar panel, battery for power supply, a magnetometer, infrared sensor, temperature sensor, 
a camera and 2.4Ghz rf transmitter to develop the satellite. We here develop a basic Cubesat design without an ACDS stabilizer system with more focus 
towards weather data gathering and transmission part.The CUBE SAT body is a cubicle shaped frame made of 4 sides. 

The 4 parts are merged to develop a cube with mounting holes for the controller, sensors, circuit board, solar panels and battery. 
The solar panels are used to generate energy that is storec in battery using charge controller and charging circuitry.

The battery charging and auto cutoff is managed by circuitry to avoid overcharging and maintain battery health. The magnetometer is used to check orientation of the cubesat.
The sensor transmits orientation data to controller. The Temperature sensor is used to measure the orbital temperature. 
Infrared sensor is mounted on top to help measure the infrared radiation from the sun and detect solar waves/blasts.

The camera is mounted at the bottom of the cubesat for capturing live footage of the earth from above. 
This footage along with the sensor data is transmitted by the controller through a 2.4Ghz RF transmitter module with a high gain antenna for max distance transmission. 
The sensor data is also displayed on an LCD Display for reference.The transmitted data is now received by a receiving station on the ground. 
The ground station circuit consists of an LCD display and footage display. The 2.4Ghz receiver is used to receive the signals from cubesat and display all the data for further processing.


Components : 

1.Stm32 Controller
2.Battery
3.Solar Panels
4.Camera Module
5.Magnetometer
6.Infrared Sensor
7.Temperature Sensor
8.LCD Display
9.RF transmitter
10.RF receiver
11.Buzzer
12.LED’s
13.PCB Board
14.Resistors
15.Capacitors
16.Transistors
17.Cables and Connectors
18.Cubesat Frame
19.Nuts and Bolts

Block Diagram : 

![image](https://github.com/InderSharma-707/weather-imaging-nanosatellite-/assets/123321936/fc31d155-a7dc-4a88-b960-d5e05cd4e0ea)
