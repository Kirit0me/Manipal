def affine_decrypt(ciphertext, a, b):
    plaintext = ''
    a_inv = pow(a, -1, 26)
    for char in ciphertext:
        if char.isalpha():
            y = ord(char) - ord('A')
            x = (a_inv * (y - b)) % 26
            plaintext += chr(x + ord('A'))
        else:
            plaintext += char

    return plaintext


ciphertext = "XPALASXYFGFUKPXUSOGEUTKCDGEXANMGNVS"
known_cipher = "GL"
known_plaintext = "AB"

known_cipher_values = [ord(c) - ord('A') for c in known_cipher]
known_plaintext_values = [ord(c) - ord('A') for c in known_plaintext]

possible_a_values = [1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25]

for a in possible_a_values:
    b = (known_cipher_values[0] - a * known_plaintext_values[0]) % 26
    decrypted_message = affine_decrypt(ciphertext, a, b)

    if decrypted_message:
        print(f"Trying a = {a}, b = {b}: {decrypted_message}")