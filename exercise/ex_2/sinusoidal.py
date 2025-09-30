import numpy as np

fs = 40000         # Sampling frequency (Hz)
t = 10             # Duration (seconds)
N = int(fs * t)    # Total samples
time = np.arange(N) / fs

# Generate x1 (2 kHz) and x2 (10 kHz) signals
x1 = np.sin(2 * np.pi * 2000 * time)
x2 = np.sin(2 * np.pi * 10000 * time)

# Combined signal
x = x1 + x2
