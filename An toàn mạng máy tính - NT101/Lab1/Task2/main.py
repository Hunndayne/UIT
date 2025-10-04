ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
alphabet = "abcdefghijklmnopqrstuvwxyz"

def encrypt(text, key):
    encrypt = ""
    for p in text:
        if p in ALPHABET:
            pos=ALPHABET.find(p)
            newPos=(pos+k)%26
            encrypt+=ALPHABET[newPos]
        elif p in alphabet:
            pos=alphabet.find(p)
            newPos=(pos+k)%26
            encrypt+=alphabet[newPos]
        else:
            encrypt+=p
    return encrypt

def decrypt(encrypted,k):
    decrypt = ""
    for c in encrypted:
        if c in ALPHABET :
            pos=ALPHABET.find(c)
            newpos=(pos-k)%26
            decrypt+=ALPHABET[newpos]
        elif c in alphabet:
            pos=alphabet.find(c)
            newpos=(pos-k)%26
            decrypt+=alphabet[newpos]
        else:
            decrypt+=c
    return decrypt

def brute_force(encrypted):
    for k in range(26):
        text = decrypt(encrypted, k)
        print(f"k={k:2d} -> {text}")


if __name__ == "__main__":
    option=int(input("1 - Encrypt\n2 - Decrypt\n"))
    if option==2:
        encrypted = input("Encrypt Text: ").strip()
        k=int(input("Key (0 = brute-force): ").strip())
        if k==0:
            brute_force(encrypted)
        else:
            decrypted=decrypt(encrypted,k)
            print(f"K={k} -> {decrypted}")
    elif option==1:
        plaintext=input("Input plaintext: ").strip()
        k=int(input("Key k="))
        print(encrypt(plaintext,k))