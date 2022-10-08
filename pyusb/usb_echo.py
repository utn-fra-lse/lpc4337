from ciaa import Ciaa, CiaaStatusCode

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
	# Wait for user input to send
	data = input("Enter something to send: ")
	# Send data through USB
	bytes_written = ciaa.write(data)
	# Read from USB
	bytes_read = ciaa.read(500)
	# Print received data
	print(f"Received: {bytes_read}")
	# Ask to continue
	if input("Continue (y/n)? ").lower() == "n":
		# End loop
		break
	
	print()
