# SnakeTracker
ESE Senior Design Project, Fall 2020

# Introduction
Hello! Our names are Matthew Bridges and Nathan Shreve, and we are undergraduate students at Washington University in St. Louis. We are currently studying Electrical Engineering, and are working to design a LoRa Network that utilizes implantable GPS end nodes to track the movement of snakes in a local nature conservancy. For our project, we are building these implantable trackers to a certain set of specifications given to us by an ecologist who works for the nature conservancy. The specifications for the implant are given as follows:

1. It must be less than 15x40mm, so that it can be implanted into the snake
2. It must have a battery life of up to 8months. This is because every time the battery is replaced, the snakes must undergo an invasive surgery
3. It must take position data at least once per day

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
    
## Schematic
The schematic for our PCB is located in our GitHub.  

## Components
The BOM is located in our GitHub. 

Significant components for the microcontroller include:
1. SAMR34: This is our microcontroller
2. SKY13373_460LF SP3T Switch: This is a switching module that we will use to connect our LoRa antenna to our MCU
3. Antenna: We will be using a simple wire antenna cut down to 1/4 wavelength for the 915MHz antenna

Significant components for the GPS module include:
1. Erinome-II: This is our GPS module
2. WE-MCA Multilayer Chip Antenna: This is our GPS antenna
3. TDK SAW RF Filter B4310: This will be our low loss RF filter for the GPS signal

## Build files
The Gerber files and drill files are located in our GitHub.

# Some Notes for our Design
The board is currently 65x22mm. We will test this version first, and then scale it down appropriately after we have a working prototype.
