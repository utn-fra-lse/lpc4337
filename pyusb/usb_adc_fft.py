from ciaa import Ciaa, CiaaStatusCode
import numpy as np
import matplotlib.pyplot as plt

# ADC clock
f_adc = 4.5e6 
# Conversion time for a 3 bit sample
conversion_time = 4 / f_adc

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
    # Get json data
    data = ciaa.read_json(100, debug = True)
    # Get the FFT values
    fft = data["values"]
    # Get list length
    n = len(fft)
    # Real sample length
    N = int(data["size"])
    # Get sampling frequency
    fs = 1 / (N * conversion_time)
    # Go from 0 to sampling frequency with N steps
    fn = np.linspace(0, fs / 2, n)
    # Take error into account
    #for i, f in enumerate(fn):
    #    fn[i] = 1.46 * f + 8.91e-1

    # Normalize amplitudes
    for i, s in enumerate(fft):
        fft[i] = s / n

    # Get rid of DC level
    fft[0] = 0.0

    # Get peak value
    peak = max(fft)
    # Get frequency index of max value
    index = fft.index(peak)

    print()
    print(f"Max value of {peak:.2f} in {fn[index]:.2f} Hz")
    print()

    # Plot settings
    plt.grid(True)
    plt.title("Sample FFT")
    plt.ylabel("Amplitude")
    plt.xlabel("Frequency [Hz]")
    plt.ylim([0, 1.5])
    plt.xlim([0, fs / 2])
    # Plot up to fs / 2 the FFT values
    plt.stem(fn, fft, linefmt="blue", markerfmt="none", label=f"{N} samples @ {fs:.2e} Hz")
    # Show label
    plt.legend()
    # Pause plot
    plt.pause(0.0005)
    # Clear plot
    plt.clf()
