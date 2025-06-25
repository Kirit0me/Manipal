# Simple DES-like Encryption and Decryption in Python

def xor(a, b):
    # XOR two bit strings of the same length
    return ''.join('1' if x != y else '0' for x, y in zip(a, b))


def initial_permutation(block):
    # Simplified Initial Permutation (IP)
    permuted = block[1] + block[5] + block[2] + block[0] + block[3] + block[7] + block[4] + block[6]
    return permuted


def final_permutation(block):
    # Simplified Final Permutation (IP^-1)
    permuted = block[3] + block[0] + block[2] + block[4] + block[6] + block[1] + block[7] + block[5]
    return permuted


def expand_half_block(half_block):
    # Expansion of the right half block (E)
    expanded = half_block[3] + half_block[0] + half_block[1] + half_block[2] + half_block[1] + half_block[2] + \
               half_block[3] + half_block[0]
    return expanded


def s_box_substitution(expanded_half_block):
    # Simplified S-Box substitution
    s_box = {
        '0000': '101',
        '0001': '010',
        '0010': '001',
        '0011': '110',
        '0100': '011',
        '0101': '100',
        '0110': '111',
        '0111': '000',
        '1000': '001',
        '1001': '110',
        '1010': '101',
        '1011': '011',
        '1100': '100',
        '1101': '111',
        '1110': '000',
        '1111': '010'
    }
    return s_box[expanded_half_block[:4]] + s_box[expanded_half_block[4:]]


def round_function(right_half, key):
    expanded_half = expand_half_block(right_half)
    xor_result = xor(expanded_half, key)
    substituted = s_box_substitution(xor_result)
    return substituted


def simple_des_encrypt(plaintext, key):
    # Assume plaintext is 8 bits, key is 8 bits
    block = initial_permutation(plaintext)
    left, right = block[:4], block[4:]

    # Round 1
    round1_result = round_function(right, key)
    left = xor(left, round1_result)

    # Swap left and right for round 2
    left, right = right, left

    # Round 2
    round2_result = round_function(right, key)
    left = xor(left, round2_result)

    # Combine and apply final permutation
    preoutput = left + right
    ciphertext = final_permutation(preoutput)
    return ciphertext


def simple_des_decrypt(ciphertext, key):
    block = initial_permutation(ciphertext)
    left, right = block[:4], block[4:]

    # Round 2 (reverse order)
    round2_result = round_function(right, key)
    left = xor(left, round2_result)

    # Swap left and right for round 1
    left, right = right, left

    # Round 1
    round1_result = round_function(right, key)
    left = xor(left, round1_result)

    # Combine and apply final permutation
    preoutput = left + right
    plaintext = final_permutation(preoutput)
    return plaintext


# Example usage
plaintext = "10101011"  # 8-bit plaintext
key = "01011010"  # 8-bit key

ciphertext = simple_des_encrypt(plaintext, key)
decrypted_text = simple_des_decrypt(ciphertext, key)

print(ciphertext, decrypted_text)
