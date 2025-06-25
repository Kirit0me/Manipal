ctk = "CIW"
ptk = "YES"
shift = (ord(ctk[0]) - ord(ptk[0]))%26

ct = "XVIEWYWI"

pt = ''.join(chr((ord(c) - shift - ord('A')) % 26 + ord('A')) for c in ct)

print(pt)