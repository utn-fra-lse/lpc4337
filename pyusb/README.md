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