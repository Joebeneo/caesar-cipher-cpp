/*
 * main.cpp
 * Caesar Cipher Tool — encrypt, decrypt, and brute-force crack Caesar ciphers
 * Author: Jeu Shane Radoc
 * Date: 2026-03-22
 * A CLI tool demonstrating the Caesar cipher, one of the oldest substitution ciphers
 */

#include <iostream>
#include <string>
#include <cctype>
#include <limits>

// Shift a single character by the given amount, preserving case
// Non-alphabetic characters pass through unchanged
char shift_char(char c, int shift)
{
    if (std::isalpha(c)) {
        char base = std::isupper(c) ? 'A' : 'a';
        // Normalize shift to 0-25 range to handle negatives and large values
        int normalized = ((shift % 26) + 26) % 26;
        return static_cast<char>(base + (c - base + normalized) % 26);
    }
    return c;
}

std::string apply_cipher(const std::string &text, int shift)
{
    std::string result;
    result.reserve(text.size());
    for (char c : text) {
        result += shift_char(c, shift);
    }
    return result;
}

std::string encrypt(const std::string &plaintext, int shift)
{
    return apply_cipher(plaintext, shift);
}

std::string decrypt(const std::string &ciphertext, int shift)
{
    // Decryption is just encryption with the negative shift
    return apply_cipher(ciphertext, -shift);
}

void brute_force(const std::string &ciphertext)
{
    std::cout << "\nBrute-force results:\n";
    for (int shift = 1; shift <= 26; ++shift) {
        std::string attempt = decrypt(ciphertext, shift);
        std::cout << "Shift " << (shift < 10 ? " " : "") << shift
                  << ": " << attempt << "\n";
    }
}

// Read shift value with basic validation — rejects non-integer input
bool read_shift(int &shift)
{
    std::cout << "Enter shift value: ";
    if (!(std::cin >> shift)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Shift must be an integer.\n";
        return false;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return true;
}

std::string read_message(const std::string &prompt)
{
    std::cout << prompt;
    std::string message;
    std::getline(std::cin, message);
    return message;
}

void print_menu()
{
    std::cout << "\n=== Caesar Cipher Tool ===\n"
              << "1. Encrypt\n"
              << "2. Decrypt\n"
              << "3. Brute-force Decrypt\n"
              << "4. Exit\n"
              << "> ";
}

int main()
{
    int choice = 0;

    while (true) {
        print_menu();

        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Enter a number 1-4.\n";
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (choice == 4) {
            std::cout << "Exiting.\n";
            break;
        }

        switch (choice) {
            case 1: {
                std::string msg = read_message("Enter message: ");
                if (msg.empty()) {
                    std::cout << "Empty message. Nothing to encrypt.\n";
                    break;
                }
                int shift = 0;
                if (read_shift(shift)) {
                    std::cout << "Encrypted: " << encrypt(msg, shift) << "\n";
                }
                break;
            }
            case 2: {
                std::string msg = read_message("Enter encrypted message: ");
                if (msg.empty()) {
                    std::cout << "Empty message. Nothing to decrypt.\n";
                    break;
                }
                int shift = 0;
                if (read_shift(shift)) {
                    std::cout << "Decrypted: " << decrypt(msg, shift) << "\n";
                }
                break;
            }
            case 3: {
                std::string msg = read_message("Enter encrypted message: ");
                if (msg.empty()) {
                    std::cout << "Empty message. Nothing to decrypt.\n";
                    break;
                }
                brute_force(msg);
                break;
            }
            default:
                std::cout << "Invalid option. Enter a number 1-4.\n";
                break;
        }
    }

    return 0;
}
