from ciaa import Ciaa, CiaaStatusCode
import numpy as np
import matplotlib.pyplot as plt
import sys

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

	# Get the FFT values
	fft = ciaa.read_json(100, debug = True)["values"]
	# Get sample length
	n = len(fft)
	# Period sampled (change if original data was changed)
	T = 5e-3
	# Normalize amplitudes
	for i, s in enumerate(fft):
		fft[i] = fft[i] / n

	# Because FFT is already cut from repeated values,
	# sampling frequency is the number of samples divided by
	# the period sampled
	fs = n / T

	# Go from 0 to sampling frequency with N steps
	fn = np.linspace(0, fs, n)

	# Plot FFT graph
	plt.grid()
	plt.title("Sample FFT")
	plt.ylabel("Amplitude")
	plt.xlabel("Frequency [Hz]")
	plt.plot(fn, fft)
	plt.show()

	sys.exit(0)