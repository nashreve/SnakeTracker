# SnakeTracker
ESE Senior Design Project, Fall 2020

# Introduction
Hello! My name is Nathan Shreve, and I'm a fourth-year undergraduate student at university. I am currently studying Electrical Engineering, and am working on a team that is designing a LoRa Network that utilizes implantable GPS end nodes to track the movement of snakes in a local nature conservancy. Outside of school, I enjoy running, hiking, and swimming, and I love to read science fiction novels! My favorite authors are Isaac Asimov and Arthur C. Clarke. 

For our project, we are building these implantable trackers to a certain set of specifications given to us by an ecologist who works for the nature conservancy. The specifications for the implant are given as follows:

1. It must be less than 15x40mm, so that it can be implanted into the snake
2. It must have a battery life of up to 8months. This is because every time the battery is replaced, the snakes must undergo an invasive surgery
3. It must take position data at least once per day

These implants will then be part of a larger LoRa Network to send data back to a central server. The data will then be accessed from a front end visualization tool. A layout of our network is shown in the "Project Overview" folder. Our project consists of four main parts:

1. The snake implants as end nodes of the network
2. The LoRa gateway, which will be mounted to a tree somewhere in the nature conservancy
3. The network server that will hold our data that we collect
4. The application server on the front end that will allow our ecologist client to access the position data stored in the network server.

# Snake Implants: Our Custom PCB
One major component of our project, as mentioned earlier, is the implant for the snakes. We have designed a custom PCB to do this. This custom PCB follows the limitations regarding size, battery life, and position, all given above. Our PCB consists of two main parts. It has a microcontroller with a LoRa radio module, and a GPS unit to take position data. That position data will then be sent out through the radio module to the rest of the LoRa network. 

For our microcontroller/radio, we decided to use the SAMR34, for three main reasons:
1. It complies with size constraints
    6x6mm BGA package IC
    We will have to design circuitry to support RF capabilities (antenna connector, RF switch). 
2. It’s ultra low power
    1.4µA standby
3. Communication requirements
    Can communicate over the 868 and 915 MHz bands
    Can use UART, SPI, or I2C to interface with the GPS

For the GPS unit, we decided to use the Wurth Electronik Erinome-II, for three main reasons:
1. It complies with size constraints
    The module is 7x7x1.6mm
2. It’s low power
    Low power consumption compared to other GPS modules, but a larger power drain than the MCU
3. Communication requirements
    Can use UART and I2C interfaces
