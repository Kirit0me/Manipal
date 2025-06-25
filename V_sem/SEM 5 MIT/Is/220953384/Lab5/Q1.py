def custom_hash(input_string):
    hash_value = 5381

    for char in input_string:
        hash_value = (hash_value * 33) + ord(char)

        hash_value = hash_value ^ ((hash_value >> 16) & 0xFFFFFFFF)

    hash_value = hash_value & 0xFFFFFFFF

    return hash_value

input_string = input("Enter Message : ")
hash_result = custom_hash(input_string)
print(f"The hash for '{input_string}' is: {hash_result}")
