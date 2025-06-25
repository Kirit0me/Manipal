from Crypto.Cipher import DES
from Crypto.Util.Padding import pad, unpad
import binascii

message = "Confidential Data"
key = b"A1B2C3D4"

cipher = DES.new(key, DES.MODE_ECB)
padded_message = pad(message.encode(), DES.block_size)
ciphertext = cipher.encrypt(padded_message)
hex_ciphertext = binascii.hexlify(ciphertext).decode()

decrypted_padded_message = cipher.decrypt(ciphertext)
decrypted_message = unpad(decrypted_padded_message, DES.block_size).decode()

print("CT: ", hex_ciphertext, "\n", "Decrypted:", decrypted_message)