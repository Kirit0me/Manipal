ogpt = "The key is hidden under the door pad"
eg1 = "hello"
eg2 = [ ['L', 'G', 'D', 'B', 'A'], ['Q', 'M', 'H', 'E', 'C'], ['U', 'R', 'N', 'I', 'F'], ['X', 'V', 'S', 'O', 'K'], ['Z', 'Y', 'W', 'T', 'P']]
key = "GUIDANCE"

def generate_table(word):
    key_letters = []
    for i in word:
        if i not in key_letters:
            key_letters.append(i)

    comp_elements = []
    for i in key_letters:
        if i not in comp_elements:
            comp_elements.append(i)
    for i in "ABCDEFGHIKLMNOPQRSTUVWXYZ":
        if i not in comp_elements:
            comp_elements.append(i)

    matrix = []
    while comp_elements != []:
        matrix.append(comp_elements[:5])
        comp_elements = comp_elements[5:]

    return matrix


def search(mat, element):
    for i in range(5):
        for j in range(5):
            if(mat[i][j] == element):
                return i, j


def encipher_pair(matrix, char1, char2):
    i1, j1 = search(matrix, char1)
    i2, j2 = search(matrix, char2)

    if i1 == i2:
        return matrix[i1][(j1 + 1) % 5] + matrix[i2][(j2 + 1) % 5]
    elif j1 == j2:
        return matrix[(i1 + 1) % 5][j1] + matrix[(i2 + 1) % 5][j2]
    else:
        return matrix[i1][j2] + matrix[i2][j1]


def prepare_text(plaintext):
    plaintext = plaintext.upper().replace('J', 'I').replace(' ', '')
    prepared_text = ""
    i = 0
    while i < len(plaintext):
        if i == len(plaintext) - 1:
            prepared_text += plaintext[i] + 'X'
            i += 1
        elif plaintext[i] == plaintext[i + 1]:
            prepared_text += plaintext[i] + 'X'
            i += 1
        else:
            prepared_text += plaintext[i] + plaintext[i + 1]
            i += 2
    return prepared_text


def playfair_encipher(pt, keyword = "default"):

    # matrix = generate_table(keyword)
    matrix = eg2
    prepared_text = prepare_text(pt)
    ct = ""

    for i in range(0, len(prepared_text), 2):
        ct += encipher_pair(matrix, prepared_text[i], prepared_text[i + 1])

    return ct

ctp = playfair_encipher(eg1)

print("Playfair Cipher : ")
print("Ciphertext:", ctp)