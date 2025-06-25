ogpt = "I am learning information security"


def encrypt_additive(msg, key):
    ct = ""
    for c in msg:
        if c.isalpha():
            if c.islower():
                ct += chr((ord(c) - ord("a") + key) % 26 + ord("a"))
            if c.isupper():
                ct += chr((ord(c) - ord("A") + key) % 26 + ord("A"))
        else:
            ct += c
    return ct


def decrypt_additive(msg, key):
    ct = ""
    for c in msg:
        if c.isalpha():
            if c.islower():
                ct += chr((ord(c) - ord("a") - key + 26) % 26 + ord("a"))
            if c.isupper():
                ct += chr((ord(c) - ord("A") - key + 26) % 26 + ord("A"))
        else:
            ct += c
    return ct


def encrypt_multiplicative(msg, key):
    ct = ""
    for c in msg:
        if c.isalpha():
            if c.islower():
                ct += chr(( (ord(c) - ord("a")) * key) % 26 + ord("a"))
            if c.isupper():
                ct += chr(( (ord(c) - ord("A")) * key) % 26 + ord("A"))
        else:
            ct += c
    return ct

def decrypt_multiplicative(msg, key):
    pt = ""
    key_inverse = pow(key, -1, 26)
    for c in msg:
        if c.isalpha():
            if c.islower():
                pt += chr(( (ord(c) - ord("a")) * key_inverse) % 26 + ord("a"))
            if c.isupper():
                pt += chr(( (ord(c) - ord("A")) * key_inverse) % 26 + ord("A"))
        else:
            pt += c
    return pt

def encrypt_affine(msg, key1, key2):
    ct = ""
    for c in msg:
        if c.isalpha():
            if c.islower():
                ct += chr(( (ord(c) - ord("a")) * key1 + key2) % 26 + ord("a"))
            if c.isupper():
                ct += chr(( (ord(c) - ord("A")) * key1 + key2) % 26 + ord("A"))
        else:
            ct += c
    return ct

def decrypt_affine(msg, key1, key2):
    pt = ""
    key_inverse = pow(key1, -1, 26)
    for c in msg:
        if c.isalpha():
            if c.islower():
                pt += chr(( (ord(c) - ord("a") - key2) * key_inverse) % 26 + ord("a"))
            if c.isupper():
                pt += chr(( (ord(c) - ord("A") - key2) * key_inverse) % 26 + ord("A"))
        else:
            pt += c
    return pt


cta = encrypt_additive(ogpt, 20)
ctm = encrypt_multiplicative(ogpt, 15)
ctaf = encrypt_affine(ogpt, 15, 20)

print("Additive cipher : ")
print(cta)
print(decrypt_additive(cta, 20))

print("Multiplicative cipher : ")
print(ctm)
print(decrypt_multiplicative(ctm, 15))


print("Affine cipher : ")
print(ctaf)
print(decrypt_affine(ctaf, 15, 20))
