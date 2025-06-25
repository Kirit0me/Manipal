ogpt = "Attack is today"
key_v = "dollars"

def encrypt_vigenere(msg, key):
    ct=""
    for i in range(len(msg)):
        if msg[i].isalpha():
            shift = ord(key[i % len(key)]) - ord('a')
            if msg[i].islower():
                ct += chr((ord(msg[i]) - ord('a') + shift) % 26 + ord('a'))
            if msg[i].isupper():
                ct += chr((ord(msg[i]) - ord('A') + shift) % 26 + ord('A'))
        else:
            ct += msg[i]
    return ct

def decrypt_vigenere(msg, key):
    pt=""
    for i in range(len(msg)):
        if msg[i].isalpha():
            shift = ord(key[i % len(key)]) - ord('a')
            if msg[i].islower():
                pt += chr((ord(msg[i]) - ord('a') - shift + 26) % 26 + ord('a'))
            if msg[i].isupper():
                pt += chr((ord(msg[i]) - ord('A') - shift + 26) % 26 + ord('A'))
        else:
            pt += msg[i]
    return pt

def encrypt_autokey(msg, key):
    ct=""
    for i in range(len(msg)):
        if msg[i].isalpha():
            if msg[i].islower():
                ct += chr((ord(msg[i]) - ord('a') + key) % 26 + ord('a'))
                key = ord(msg[i]) - ord('a')
            if msg[i].isupper():
                ct += chr((ord(msg[i]) - ord('A') + key) % 26 + ord('A'))
                key = ord(msg[i]) - ord('A')
        else:
            ct += msg[i]
    return ct

def decrypt_autokey(msg, key):
    pt = ""
    for i in range(len(msg)):
        if msg[i].isalpha():
            if msg[i].islower():
                pt += chr((ord(msg[i]) - ord('a') - key + 26) % 26 + ord('a'))
            if msg[i].isupper():
                pt += chr((ord(msg[i]) - ord('A') - key + 26) % 26 + ord('A'))

            if pt[-1].isupper():
                key = ord(pt[-1]) - ord('A')
            else:
                key = ord(pt[-1]) - ord('a')
        else:
            pt += msg[i]
    return pt

ctv = encrypt_vigenere(ogpt, key_v)
cta = encrypt_autokey(ogpt, 12)

print("Vignere Cipher : ")
print(ctv)
print(decrypt_vigenere(ctv, key_v))

print("Autokey cipher : ")
print(cta)
print(decrypt_autokey(cta, 12))
