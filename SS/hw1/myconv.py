import numpy as np
import matplotlib.pyplot as plt

# Define the signals
def signal_1(n):
    if 1 <= n <= 20:
        return n
    elif 21 <= n <= 39:
        return 40 - n
    else:
        return 0

def signal_2(n):
    if n < 1:
        return 0
    elif n == 1:
        return 1
    else:
        return signal_2(n-1) - signal_2(n-11)

# (a) Plot signals
n_values = np.arange(1, 40)
signal1_values = [signal_1(n) for n in n_values]
signal2_values = [signal_2(n) for n in n_values]

plt.stem(n_values, signal1_values, label='Signal 1')
plt.xlabel('n')
plt.ylabel('Amplitude')
plt.title('Plot of Signal 1')
plt.legend()
plt.show()

plt.stem(n_values, signal2_values, label='Signal 2')
plt.xlabel('n')
plt.ylabel('Amplitude')
plt.title('Plot of Signal 2')
plt.legend()
plt.show()

# (b) Convolve signals using numpy.convolve
conv_result = np.convolve(signal1_values, signal2_values, mode='full')

plt.stem(np.arange(1, len(conv_result)+1), conv_result)
plt.xlabel('n')
plt.ylabel('Amplitude')
plt.title('Convolution using numpy.convolve')
plt.show()

# (c) Convolve signals using matrix form
def convolution_matrix(signal1, signal2):
    len1 = len(signal1)
    len2 = len(signal2)
    result_length = len1 + len2 - 1
    convolution_matrix = np.zeros((result_length, len1))

    for i in range(result_length):
        for j in range(len1):
            if i - j >= 0 and i - j < len2:
                convolution_matrix[i, j] = signal2[i - j]

    return np.dot(convolution_matrix, signal1)

conv_result_matrix = convolution_matrix(signal1_values, signal2_values)

plt.stem(np.arange(1, len(conv_result_matrix)+1), conv_result_matrix)
plt.xlabel('n')
plt.ylabel('Amplitude')
plt.title('Convolution using matrix form')
plt.show()

# (d) using different signals
def sig_1(n):
    if 1 <= n <= 3:
        return 3 ** n
    else:
        return 0

def sig_2(n):
    if 1 <= n <= 5:
        return 2 ** n
    else:
        return 0

# (a) Plot signals
n_values = np.arange(1, 6)
signal1_values = [sig_1(n) for n in n_values]
signal2_values = [sig_2(n) for n in n_values]

plt.stem(n_values, signal1_values, label='Signal 1')
plt.xlabel('n')
plt.ylabel('Amplitude')
plt.title('Plot of Signal 1')
plt.legend()
plt.show()

plt.stem(n_values, signal2_values, label='Signal 2')
plt.xlabel('n')
plt.ylabel('Amplitude')
plt.title('Plot of Signal 2')
plt.legend()
plt.show()

# (b) Convolve signals using numpy.convolve
conv_result = np.convolve(signal1_values, signal2_values, mode='full')

plt.stem(np.arange(1, len(conv_result)+1), conv_result)
plt.xlabel('n')
plt.ylabel('Amplitude')
plt.title('Convolution using numpy.convolve')
plt.show()

# (c) Convolve signals using matrix form
conv_result_matrix = convolution_matrix(signal1_values, signal2_values)

plt.stem(np.arange(1, len(conv_result_matrix)+1), conv_result_matrix)
plt.xlabel('n')
plt.ylabel('Amplitude')
plt.title('Convolution using matrix form')
plt.show()