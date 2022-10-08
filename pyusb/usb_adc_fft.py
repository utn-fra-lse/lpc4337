import usb.core
import usb.backend.libusb1
import json
import numpy as np
import matplotlib.pyplot as plt
import time

# LPC4337 IDs and Endpoints
VENDOR_ID = 0x1fc9
PRODUCT_ID = 0x008a
WRITE_ED = 0x01
READ_ED = 0x81

# Conversion time for a 10 bit sample
conversion_time = 25e-6
# Get sampling frequency
fs = 1 / conversion_time
# Sample length
N = 2048


def usb_read(dev: usb.core.Device, timeout: int) -> str:
	"""
	Reads a string from USB

	params:
		dev (Device): device to read
		timeout (int): time to wait in ms

	return: (str) String read
	"""
	try:
		# Try to read bytes (returns list)
		data = dev.read(READ_ED, 128, timeout)
	except usb.core.USBError as e:
		# Catch exception and return None
		return None

	# Join list to a string
	byte_str = ''.join(chr(n) for n in data) 
	# Remove null characters
	result = byte_str.split('\x00', 1)[0]
	# If nothing was read
	if len(result) == 0:
		# Return empty
		return None
	# Return full string
	return result


# Find device by vendor and product IDs
dev = usb.core.find(idVendor=VENDOR_ID, idProduct=PRODUCT_ID)

# Check if it was found
if dev is None:
	# If not, raise error
	raise ValueError("Device not found")

# If it was found, print message
print("CIAA found!")
print("-" * 80)
print()


while True:

    bytes_read = ""
    data = ""
    # Starting time timestamp
    start_time = time.time()

    # Look for closing JSON character
    while not "}" in bytes_read:
        # Read from USB
        bytes_read = usb_read(dev, 500)
        # Check if any byte was read
        if bytes_read != None:
            # Add bytes to data
            data += bytes_read
        else:
            # Clear bytes
            bytes_read = ""

    # Show how much time it has passed since the beginnig of the transfer
    print(f"Data transfer done in: {(time.time() - start_time):.2e}s")
    # Build JSON like object with byte array data
    data = json.loads(data)
    # Get the FFT values
    fft = data["values"]
    # Get list length
    n = len(fft)
    # Go from 0 to sampling frequency with N steps
    fn = np.linspace(0, fs / 2, n)
    # Normalize amplitudes
    for i, s in enumerate(fft):
        fft[i] = fft[i] / N

    # Plot settings
    plt.grid(True)
    plt.title("Sample FFT")
    plt.ylabel("Amplitude")
    plt.xlabel("Frequency [Hz]")
    plt.ylim([0, 0.5])
    plt.xlim([0, 20e3])
    # Plot up to fs / 2 the FFT values
    plt.stem(fn, fft, linefmt="blue", markerfmt="none")
    # Pause plot
    plt.pause(0.001)
    # Clear plot
    plt.clf()
