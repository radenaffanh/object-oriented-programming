import numpy as np 
import matplotlib.pyplot as plt 
from scipy.signal import lti, step 

# === Parameter RLC NFC === 
R = 16.8               # Ohm 
L = 5.95e-6            # Henry 
C = 23e-12             # Farad 

# === Fungsi alih sistem RLC seri === 
# H(s) = (1/LC) / (s^2 + (R/L)*s + 1/(LC)) 
num = [1/(L*C)] 
den = [1, R/L, 1/(L*C)] 
system = lti(num, den) 

# === Simulasi step response === 
t = np.linspace(0, 4e-6, 1500) 
t, y = step(system, T=t) 

# === Step input (unit step u(t)) === 
step_input = np.ones_like(t) 

# === Plot Input dan Output === 
plt.figure(figsize=(9,6)) 

# --- Subplot 1: Input Step --- 
plt.subplot(2,1,1) 
plt.plot(t * 1e6, step_input, color='blue', linewidth=2, label='Step Input u(t)') 
plt.title("Step Input Signal (u(t))", fontsize=12) 
plt.ylabel("Amplitude (V)") 
plt.grid(True) 
plt.legend(loc="upper right") 

# --- Subplot 2: Output Step Response --- 
plt.subplot(2,1,2) 
plt.plot(t * 1e6, y, color='red', linewidth=2, label='Step Response y(t)') 
plt.title("Step Response of NFC RLC Circuit", fontsize=12) 
plt.xlabel("Time (µs)") 
plt.ylabel("Amplitude (Vc)") 
plt.grid(True) 
plt.legend(loc="upper right") 

plt.tight_layout() 
plt.show()