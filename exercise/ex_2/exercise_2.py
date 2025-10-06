import numpy as np
import matplotlib.pyplot as plt
from scipy import signal  
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

# 2) Create signal x = x1 + x2
x = x1 + x2
plt.figure(figsize=(12, 4))
plt.plot(n[:1000], x[:1000], 'm', label='x = x1 + x2')
plt.title('Signal x = x1 + x2')
plt.xlabel('Time [s]')
plt.ylabel('Amplitude')
plt.legend()  # add legend
plt.tight_layout()
plt.savefig('signal_sum.png')
plt.show()
plt.close()

# 3) FIR filter to remove x1 from x (using high-pass filter - keep x2)
# Choose cutoff frequency = 5000 Hz (between f1 and f2)
wC = 5000  # Cutoff frequency (Hz)
Nf = 101  # Filter order
h_hp = signal.firwin(Nf, wC, pass_zero=False, window='hamming', fs=fs)
# Apply the high-pass filter to x to get y_hp
y_hp = signal.lfilter(h_hp, 1.0, x)
plt.figure(figsize=(12, 4))
plt.plot(n[:600], x[:600], 'm', label='x (Input Signal)')
plt.plot(n[:600], y_hp[:600], 'r', label='y_hp (High-pass filtered)')
plt.title('Signal y_hp (After High-pass Filter)')
plt.xlabel('Time [s]')
plt.ylabel('Amplitude')
plt.legend()  # add legend
plt.tight_layout()
plt.savefig('signal_highpass.png')
plt.show()
plt.close()

# 4) FIR filter to remove x2 from x (using low-pass filter - keep x1)
# Choose cutoff frequency = 5000 Hz (between f1 and f2)
h_lp = signal.firwin(Nf, wC, pass_zero=True, window='hamming', fs=fs)
# Apply the low-pass filter to x to get y_lp
y_lp = signal.lfilter(h_lp, 1.0, x)
plt.figure(figsize=(12, 4))
plt.plot(n[:500], x[:500], 'm', label='x (Input Signal)')
plt.plot(n[:500], y_lp[:500], 'b', label='y_lp (Low-pass filtered)')
plt.title('Signal y_lp (After Low-pass Filter)')
plt.xlabel('Time [s]')
plt.ylabel('Amplitude')
plt.legend()  # add legend
plt.tight_layout()
plt.savefig('signal_lowpass.png')
plt.show()
plt.close()