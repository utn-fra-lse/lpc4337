# CIAA API

This repository contains some API for the LPC4337 based boards. The purpose of this API is to make the development with such devices easier.

Low level and high level libraries are given to work with the available peripherials. All of it is written in C.

## Repository organization

### api

This directory includes all the libraries necessaries to work with the LPC4337. It is a self contained library, so it can be imported or referenced from the MCUXpresso to work with any new project.

### chip

LPC43337 chip libraries for the MCUXpresso. Supports M4 and M0 cores. API is dependant on this libraries so it needs to be imported or referenced from the MCUXpresso's workspace in orther for the API to work.

### cmsis

Stands for Common Microcontroller Software Interface Standard. This directory includes the latest source code for a DSP library with some fixes that is specially designed for complex math in embedded systems with ARM architcture.

### config

This directory has some `.xml` files that can be imported into a new project to easily configure all the paths to the api and the memory bank for the M0 core in dual core applications.

### etc

This one contains a [lpc4337.cfg][cfg] file theat allows the MCUXpresso to be able to program and debug the current project with openocd. It also contains a legacy config file for an older version of the openocd (0.9.0).

### examples

This one contains some examples for the API for every peripherial.

### pyusb

This directory has some info on the [pyusb][pyusb] Python package, which is used to communicate with the OTG USB on the CIAA board. Some Python scripts are there also to test the currently supported USB examples.

## About multicore projects

Multicore projects need some special attention to configure. Please follow this steps:

### M0APP project

1- First, create a new LPCOpen-C Project for the `LPC4337-M0`. Choose the LPC43xx Multicore M0APP option in the Wizard window.

2- Make sure that the `lpc_chip_43xx_m0` library is chosen.

3- When you get to the memory configuration window you can either choose to import the `m0app_memory.xml` file located in [config](config/) directory or you can configure it by yourself. If you choose the second option then:

- Remove the first block of Flash allocated in `0x1a000000`. Only leave the second block in `0x1b000000`.

- Remove the first block of RAM allocated in `0x10000000`. Leave the other four RAM blocks from `0x200000000` to `0x2000c000`.

4- You can finish the rest of the project initialization and configure anything else as you wish.

### M4 project

1- Create a new LPCOpen-C Project for the `LPC4337`. Choose the LPC43xx Multicore M4 option in the Wizard window.

2- Make sure that the `lpc_chip_43xx` library is chosen.

3- The memory blocks can be left as default.

4- In the M0APP Slave Project Settings window, select the previous M0APP project as the M0APP Slave Project and check the box that says _Use 2nd flash block in dual bank flash MCU_.

5- Complete the rest of the project initialization as you wish.

[cfg]: etc/openocd/lpc4337.cfg
[cmsis]: https://developer.arm.com/tools-and-software/embedded/cmsis
[pyusb]: https://github.com/pyusb/pyusb