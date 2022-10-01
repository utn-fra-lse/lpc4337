import usb.core
import usb.backend.libusb1
from time import sleep

# LPC4337 IDs and Endpoints
VENDOR_ID = 0x1fc9
PRODUCT_ID = 0x008a
WRITE_ED = 0x01
READ_ED = 0x81

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
		# Catch and print exception
		print(f"Error reading response: {e.args}")
		# Return empty
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
	# Read from USB
	bytes_read = usb_read(dev, 500)
	# Print received data
	print(f"Received: {bytes_read}", end="")
	# Ask to continue
	sleep(1)