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
conversion_time = 2.45e-6
# Get sampling frequency
fs = 1 / conversion_time

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

    print(f"Data transfer done in: {(time.time() - start_time):.2e}s")

    # Build JSON like object with byte array data
    data = json.loads(data)
    # Get the FFT values
    fft = data["values"]
    # Get sample length
    n = len(fft)
    # Normalize amplitudes
    for i, s in enumerate(fft):
        fft[i] = fft[i] / n

    # Remove DC offset
    fft[0] = 0.0

    # Go from 0 to sampling frequency with N steps
    fn = np.linspace(0, fs / 2, n)

    # Plot FFT graph
    plt.grid()
    plt.title("Sample FFT")
    plt.ylabel("Amplitude")
    plt.xlabel("Frequency [Hz]")
    plt.ylim([0, 0.5])
    plt.xlim([0, 20e3])
    # Plot up to fs / 2 the FFT values
    plt.plot(fn, fft, label=f"Fs: {(fs):.2e} Hz", color="blue")
    plt.legend()
    # Pause to gather new data
    plt.pause(.5)
    # Clear plot
    plt.clf()