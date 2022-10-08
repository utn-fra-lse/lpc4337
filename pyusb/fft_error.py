import numpy as np
import matplotlib.pyplot as plt

freq = [f for f in range(2500, 20000, 2500)]
#err = [2812.5, 5703.125, 8515.625, 11328.125, 14218.75, 17031.25, 19843.75]
err = [1406.25, 2851.5625, 4257.8125, 5564.0625, 7109.375, 8515.625, 9921.875]

f = np.polyfit(err, freq, 1)

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