
ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

def sanitize(s):
    s = s.upper()
    s = "".join(ch for ch in s if 'A' <= ch <= 'Z')
    return s.replace('J', 'I')

def print_grid(grid):
    print("\nMa trận:")
    for row in grid:
        print("| " + " ".join(row) + " |")
    print("----------------------------\n")

def build_square(key, print_key_square=True):
    key = sanitize(key)
    seen = set()
    order = []
    for ch in key:
        if ch not in seen:
            seen.add(ch)
            order.append(ch)
    for ch in ALPHABET:
        if ch == 'J':
            continue
        if ch not in seen:
            seen.add(ch)
            order.append(ch)
   
    grid = [order[i*5:(i+1)*5] for i in range(5)]
   
    if print_key_square:
        print_grid(grid)
       
    pos = {grid[r][c]: (r, c) for r in range(5) for c in range(5)}
    pos['J'] = pos['I']
    return grid, pos

def digraphs(text, filler='X'):
    t = sanitize(text)
    pairs = []
    i = 0
    while i < len(t):
        a = t[i]
        if i + 1 < len(t):
            b = t[i+1]
            if a == b:
                pairs.append((a, filler))
                i += 1
            else:
                pairs.append((a, b))
                i += 2
        else:
            pairs.append((a, filler))
            i += 1
    return pairs

def enc_pair(a, b, pos, grid):
    r1, c1 = pos[a]
    r2, c2 = pos[b]
    if r1 == r2:
        return grid[r1][(c1+1)%5], grid[r2][(c2+1)%5]
    if c1 == c2:
        return grid[(r1+1)%5][c1], grid[(r2+1)%5][c2]
    return grid[r1][c2], grid[r2][c1]

def dec_pair(a, b, pos, grid):
    r1, c1 = pos[a]
    r2, c2 = pos[b]
    if r1 == r2:
        return grid[r1][(c1-1)%5], grid[r2][(c2-1)%5]
    if c1 == c2:
        return grid[(r1-1)%5][c1], grid[(r2-1)%5][c2]
    return grid[r1][c2], grid[r2][c1]

def playfair_encrypt(key, text):
    grid, pos = build_square(key)
    out = []
    for a, b in digraphs(text):
        x, y = enc_pair(a, b, pos, grid)
        out.append(x + y)
    return "".join(out)

def playfair_decrypt(key, text):
    grid, pos = build_square(key)
    t = sanitize(text)
    if len(t) % 2 != 0:
        raise ValueError("Văn bản mã hóa phải có số lượng ký tự chẵn.")
    out = []
    for i in range(0, len(t), 2):
        a, b = t[i], t[i+1]
        x, y = dec_pair(a, b, pos, grid)
        out.append(x + y)
    return "".join(out)

if __name__ == "__main__":

    print("Playfair Cipher Tool")
   
    option_input = input("1 - Encrypt\n2 - Decrypt\nChọn: ").strip()
    try:
        option = int(option_input)
    except ValueError:
        print("Lựa chọn không hợp lệ. Thoát.")
        exit()

    key = input("Key: ").strip()
    text = input("Text: ").strip()
   
    if option == 1:
        print("\nKết quả Mã hóa:")
        ciphertext = playfair_encrypt(key, text)
        print("Văn bản mã hóa:", ciphertext)
    elif option == 2:
        print("\nKết quả Giải mã:")
        try:
            plaintext = playfair_decrypt(key, text)
            print("Văn bản giải mã:", plaintext)
        except ValueError as e:
            print("Lỗi:", e)
    else:
        print("Lựa chọn không hợp lệ. Vui lòng chọn 1 hoặc 2.")
