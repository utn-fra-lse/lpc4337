import numpy as np
import matplotlib.pyplot as plt

freq = [f for f in range(2500, 10000, 2500)]
# Error measured for multicore_adc_fft example at 64 samples
err = [3295.9, 6591.8, 8789.06]

# Fit a linear function with those values
f = np.polyfit(err, freq, 1)

# Values to plot
error = [er for er in range(0, 20000)]
frequency = np.polyval(f, error)

plt.grid()
plt.ylabel("Frequency [Hz]")
plt.xlabel("Error [Hz]")
plt.title("CMSIS error")
plt.plot(error, frequency, label=f"e(f) = {f[0]:.2f}f + {f[1]:.2e}")
plt.plot(err, freq, 'ro')
plt.legend()
plt.show()