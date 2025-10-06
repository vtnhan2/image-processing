import numpy as np
import matplotlib.pyplot as plt

fs = 40000  # sample rate 40 kHz
t = 10  # time 10 seconds
N = int(fs * t)  # number of samples
n = np.linspace(0, t, N, endpoint=False)  # time vector

# 1) Create signals x1 (2 kHz), x2 (10 kHz)
f1 = 2000
f2 = 10000
x1 = np.sin(2 * np.pi * f1 * n)
x2 = np.sin(2 * np.pi * f2 * n)

# Plotting
plt.figure(figsize=(12, 6))

# Plot signal x1 (2 kHz) - show first 1000 samples for clarity
plt.subplot(2, 1, 1)
plt.plot(n[:1000], x1[:1000], 'g', label='2 kHz')
plt.title('Signal x1 (2 kHz)')
plt.xlabel('Time [s]')
plt.ylabel('Amplitude')
plt.legend()  # add legend

# Plot signal x2 (10 kHz) - show first 1000 samples for clarity
plt.subplot(2, 1, 2)
plt.plot(n[:1000], x2[:1000], 'b', label='10 kHz')
plt.title('Signal x2 (10 kHz)')
plt.xlabel('Time [s]')
plt.ylabel('Amplitude')
plt.legend()  # add legend

plt.tight_layout()
plt.savefig('signal.png')
plt.show()
plt.close()