# pyusb

This directory contains a couple of Python scripts to be used with the USB CIAA examples. Currently works only on Linux based machines.

## udev rules

The use of the pyusb requires some rules to enable the communication with the USB device. To do that, copy the `pyusb.rules` file into the `/etc/udev/rules.d` directory and restart the service:

```bash
sudo cp pyusb.rules /etc/udev/rules.d
sudo service udev restart
```

## virtual environment

The following steps are necessary in order for the scripts to work. A virtual environment will be required, so first install the venv package and create the virtual environment:

```bash
python3 -m pip install venv
python3 -m venv env
```

Then, move into the virtual environment, activate it and install the necessary dependencies:

```bash
cd env
source bin/activate
python3 -m pip install ../requirements.txt
```

Now, you can run any of the scripts from the virtual environment with the following command:

```bash
sudo env "PATH=$PATH" python3 ../usb_hello_world.py
```

The command `sudo` is required to access the USB device but because there are no Python packages installed in the root user, the `PATH` environment variable needs to be used in order to get the installed packages in the virtual environment.
When you want to exit the virtual environment, run:

```bash
deactivate
```

## Example scripts

| Name | Related project | Description |
| --- | --- | --- |
| [usb_hello_world][hello_world_py] | [usb_hello_world][hello_world_c] | Constantly reads from the USB buffer and prints the message (Hello world!)
| [usb_echo][usb_echo_py] | [usb_echo][usb_echo_c] | Gets user input, sends it to the CIAA board and reads it back
| [usb_fft][usb_fft_py] | [usb_fft][usb_fft_c] | Reads an FFT output in JSON format produced by the CIAA from a set data array and then plots the result
| [fft_test][fft_test_ipynb] | [fft_test][fft_cfft_c] | It has two code pieces. The first one generates a complex sine wave data set that can be used in the CIAA example. The second one can be used to paste the CIAA output calculation and plot the result to compare
| [usb_adc_fft][usb_adc_fft_py] | [multicore_adc_fft][multicore_adc_fft_c] | Works in a similar way as the `usb_fft` but plot in real time the data that is read by the ADC

[hello_world_py]: usb_hello_world.py
[hello_world_c]: ../examples/usb/usb_hello_world/
[usb_echo_py]: usb_echo.py
[usb_echo_c]: ../examples/usb/usb_echo/
[usb_fft_py]: usb_fft.py
[usb_fft_c]: ../examples/usb/usb_fft/
[fft_test_ipynb]: fft_test.ipynb
[fft_cfft_c]: ../examples/cmsis/fft/fft_cfft/
[usb_adc_fft_py]: usb_adc_fft.py
[multicore_adc_fft_c]: ../examples/multicore/multicore_adc_fft/multicore_adc_fft_m4/