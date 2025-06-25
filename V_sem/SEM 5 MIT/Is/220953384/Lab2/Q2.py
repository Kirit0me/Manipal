from Crypto.Cipher import AES
from Crypto.Util.Padding import pad, unpad
import binascii

message = "Sensitive Information"
key = b"0123456789ABCDEF0123456789ABCDEF"

cipher = AES.new(key, AES.MODE_ECB)
padded_message = pad(message.encode(), AES.block_size)
ciphertext = cipher.encrypt(padded_message)
hex_ciphertext = binascii.hexlify(ciphertext).decode()

decrypted_padded_message = cipher.decrypt(ciphertext)
decrypted_message = unpad(decrypted_padded_message, AES.block_size).decode()

print("Ciphertext : ", hex_ciphertext)
print("Plaintext : ", decrypted_message)