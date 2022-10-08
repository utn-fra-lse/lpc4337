from ciaa import Ciaa, CiaaStatusCode
from time import sleep

# Initialize CIAA usb handler
ciaa = Ciaa()
# Look up for a conection

if ciaa.find() != CiaaStatusCode.CIAA_FOUND:
    # Raise error
    raise ValueError("CIAA not found")

# If it was found, print message
print("CIAA found!")
print("-" * 80)
print()

while True:
	# Read from USB
	bytes_read = ciaa.read(500)
	# Print received data
	print(f"Received: {bytes_read}", end="")
	# Wait for new data
	sleep(1)