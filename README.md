# CIAA API

This repository contains some API for the LPC4337 based boards. The purpose of this API is to make the development with such devices easier.

Low level and high level libraries are given to work with the available peripherials. All of it is written in C/C++.

# Repository organization

## api

This directory includes all the libraries necessaries to work with the LPC4337. It is a self contained library, so it can be imported or referenced from the MCUXpresso to work with any new project.

## chip

LPC43337 chip libraries for the MCUXpresso. Supports M4 and M0 cores. API is dependant on this libraries so it needs to be imported or referenced from the MCUXpresso's workspace in orther for the API to work.

## etc

This one contains a [lpc4337.cfg][cfg] file theat allows the MCUXpresso to be able to program and debug the current project with openocd.

## examples

This one contains some examples for the API for every peripherial.

## libusb

This directory has a simple app to test the USB in the CIAA.

[cfg]: etc/openocd/lpc4337.cfg