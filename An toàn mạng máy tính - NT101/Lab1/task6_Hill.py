ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
MODULO = len(ALPHABET)
INDEX = {ch: i for i, ch in enumerate(ALPHABET)}  # tra cứu O(1)

def text_to_number(text):
    nums = []
    for ch in text:
        if ch in INDEX:
            nums.append(INDEX[ch])
    return nums

def number_to_text(nums):
    return "".join(ALPHABET[n] for n in nums)

def mod_inverse(a, m):
    a %= m
    for x in range(1, m):
        if (a * x) % m == 1:
            return x
    return None

def get_key_matrix_inverse(key):
    det = (key[0][0] * key[1][1] - key[0][1] * key[1][0]) % MODULO
    inv = mod_inverse(det, MODULO)
    if inv is None:
        raise ValueError("Ma trận khóa không có nghịch đảo (det không nguyên tố cùng MODULO).")
    adj = [
        [key[1][1], -key[0][1]],
        [-key[1][0], key[0][0]]
    ]
    return [[(adj[i][j] * inv) % MODULO for j in range(2)] for i in range(2)]

def hill_encrypt(plaintext, key):
    # ghi lại vị trí ký tự KHÔNG thuộc A-Z/a-z
    structure = [(i, ch) for i, ch in enumerate(plaintext) if ch not in INDEX]
    letters = "".join(ch for ch in plaintext if ch in INDEX)

    if len(letters) % 2 == 1:
        letters += "X"  # đệm

    P = text_to_number(letters)
    C = []
    for i in range(0, len(P), 2):
        p1, p2 = P[i], P[i + 1]
        c1 = (key[0][0] * p1 + key[0][1] * p2) % MODULO
        c2 = (key[1][0] * p1 + key[1][1] * p2) % MODULO
        C.extend([c1, c2])

    result = list(number_to_text(C))
    for pos, ch in structure:
        if pos <= len(result):
            result.insert(pos, ch)
        else:
            result.append(ch)
    return "".join(result)

def hill_decrypt(ciphertext, key):
    structure = [(i, ch) for i, ch in enumerate(ciphertext) if ch not in INDEX]
    letters = "".join(ch for ch in ciphertext if ch in INDEX)

    if len(letters) % 2 == 1:
        raise ValueError("Bản mã có số ký tự chữ lẻ — không hợp lệ cho Hill 2x2.")

    inv_key = get_key_matrix_inverse(key)
    C = text_to_number(letters)
    P = []
    for i in range(0, len(C), 2):
        c1, c2 = C[i], C[i + 1]
        p1 = (inv_key[0][0] * c1 + inv_key[0][1] * c2) % MODULO
        p2 = (inv_key[1][0] * c1 + inv_key[1][1] * c2) % MODULO
        P.extend([p1, p2])

    result = list(number_to_text(P))
    for pos, ch in structure:
        if pos <= len(result):
            result.insert(pos, ch)
        else:
            result.append(ch)
    return "".join(result)

if __name__ == "__main__":
    try:

        key_nums = list(map(int, input("Nhập khóa (4 số cách nhau bởi dấu cách): ").split()))
        if len(key_nums) != 4:
            raise ValueError("Khóa lỗi.")
        key = [[key_nums[0], key_nums[1]], [key_nums[2], key_nums[3]]]
        print (key)
        get_key_matrix_inverse(key) 

        choice = input("e - Encrypt \n d - Decrypt").lower()

        if choice == 'e':
            plaintext = input("Nhập văn bản mã hóa: ")
            print(f"-> Cipher Text: {hill_encrypt(plaintext, key)}")
        elif choice == 'd':
            ciphertext = input("Nhập văn bản giải mã: ")
            print(f"-> Plain Text: {hill_decrypt(ciphertext, key)}")
        else:
            print("Lựa chọn không hợp lệ.")

    except ValueError as e:
        print(f"Lỗi: {e}")
    except Exception as e:
        print(f"Lỗi: {e}")