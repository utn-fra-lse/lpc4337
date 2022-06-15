import usb.core
import usb.backend.libusb1
import sys
import json

def usb_write(dev, msg):

	msg_json = json.dumps(str(msg))
	byte_str = msg_json #chr(0x01) + msg + chr(0) * max(7 - len(msg), 0)

	num_bytes_written = 0

	try:
		num_bytes_written = dev.write(0x01, msg_json)
	except usb.core.USBError as e:
		print(e.args)

	return num_bytes_written


def usb_read(dev, timeout):

	try:
		data = dev.read(0x01, 128, timeout)
	except usb.core.USBError as e:
		print(f"Error reading response: {e.args}")
		return None

	#data_str = str(json.loads(data))
	byte_str = ''.join(chr(n) for n in data) # start from the second byte
	print(data)
	result_str = byte_str.split('\x00', 1)[0] # remove the trailing null characters

	if len(result_str) == 0:
		return None

	return result_str


VENDOR_ID = 0x1fc9
PRODUCT_ID = 0x008a

dev = usb.core.find(idVendor=VENDOR_ID, idProduct=PRODUCT_ID)

if dev is None:
	raise ValueError("Device not found")
	sys.exit(1)

print("Device found!")
dat = { "msg" : "IMPA" }

print(f"To send: {dat}")
bytes_written = usb_write(dev, dat)

bytes_read = usb_read(dev, 200)

print(f"Received: {bytes_read}")

usb.util.release_interface(dev, 0)