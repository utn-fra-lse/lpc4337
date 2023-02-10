from ciaa import Ciaa, CiaaStatusCode
import numpy as np
import matplotlib.pyplot as plt
import sys

# Sampling frequency
fs = 96e3

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

try:

    while True:
        # Get json data
        data = ciaa.read_json(100, debug = True)
        # Get the FFT values
        fft = data["values"]
        # Get list length
        n = len(fft)
        # Real sample length
        N = int(data["size"])
        # Get number of clocks
        nclocks = int(data["nclocks"])
        # Get resolution bits
        resolution = ciaa.get_resolution_bits(nclocks)
        # Go from 0 to sampling frequency with N steps
        fn = np.linspace(0, fs / 2, n)

        # Normalize amplitudes
        for i, s in enumerate(fft):
            fft[i] = s / n

        # Get rid of DC level
        fft[0] = 0.0

        # Get peak value
        peak = max(fft)
        # Get frequency index of max value
        index = fft.index(peak)

        print(f"Max value of {peak:.2f} in {fn[index]:.2f} Hz")
        print()

        # Plot settings
        plt.figure("CIAA FFT")
        plt.grid(True)
        plt.title("Sample FFT")
        plt.ylabel("Amplitude [V]")
        plt.xlabel("Frequency [Hz]")
        plt.ylim([0, 1.7])
        plt.xlim([0, 20e3])
        # Plot up to fs / 2 the FFT values
        plt.stem(fn, fft, linefmt="blue", markerfmt="none", label=f"{N} samples @ {fs:.2e} Hz ({resolution} bit resolution)")
        # Plot max frequency bin
        plt.stem(fn[index], peak, linefmt="blue", label=f"Max value of {peak:.2f} V @ {fn[index]:.2f} ± {fs / (2 * n)} Hz")
        # Show label
        plt.legend()
        # Pause plot
        plt.pause(0.0005)
        # Clear plot
        plt.clf()

except KeyboardInterrupt:

    print()
    print("Interface closed")
    sys.exit(0)