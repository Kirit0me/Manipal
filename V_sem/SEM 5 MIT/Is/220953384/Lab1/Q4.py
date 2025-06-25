import numpy as np

K = np.array([[3, 3], [2, 7]])
pt = "WELIVEINANINSECUREWORLD"

message_nums = [ord(char)-ord('A') for char in pt]

if len(message_nums) % 2 != 0:
    message_nums.append(ord('X') - ord('A'))

pairs = [(message_nums[i], message_nums[i + 1]) for i in range(0, len(message_nums), 2)]
cipher_nums = []
for pair in pairs:
    vector = np.array(pair).reshape(2, 1)
    cipher_vector = np.dot(K, vector) % 26
    cipher_nums.extend(cipher_vector.flatten())

cipher_text = ''.join(chr(num + ord('A')) for num in cipher_nums)

print("Ciphertext : ", cipher_text)
