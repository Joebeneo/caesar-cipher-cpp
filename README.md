# caesar-cipher-cpp

A command-line Caesar cipher tool that encrypts, decrypts, and brute-force cracks messages.

## What it does

- Encrypts plaintext using a shift key (Caesar cipher)
- Decrypts ciphertext when you know the shift value
- Brute-force mode tries all 26 shifts to crack a message without the key
- Preserves letter case and leaves non-alphabetic characters untouched
- Handles negative shifts and values greater than 26

## Compile and run

```bash
g++ -std=c++17 -Wall -Wextra -o caesar main.cpp
./caesar
```

## Example usage

```
=== Caesar Cipher Tool ===
1. Encrypt
2. Decrypt
3. Brute-force Decrypt
4. Exit
> 1
Enter message: Hello World
Enter shift value: 3
Encrypted: Khoor Zruog

=== Caesar Cipher Tool ===
1. Encrypt
2. Decrypt
3. Brute-force Decrypt
4. Exit
> 3
Enter encrypted message: Khoor Zruog
Brute-force results:
Shift  1: Jgnnq Yqtnf
Shift  2: Ifmmp Xpsme
Shift  3: Hello World
Shift  4: Gdkkn Vnqkc
Shift  5: Fcjjm Umpjb
...
Shift 26: Khoor Zruog
```

## What I learned

The Caesar cipher is a substitution cipher where each letter shifts by a fixed number of positions in the alphabet. It's trivially breakable, with only 26 possible keys, brute-force takes microseconds. This project demonstrates why simple substitution ciphers are not suitable for real-world encryption and how modular arithmetic is used in basic cryptographic operations.

## Author

Jeu Shane Radoc — BS Computer Engineering, TUP-Visayas
