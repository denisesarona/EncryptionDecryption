# Simple Encryption and Decryption System

## Overview

This project is a Simple Encryption and Decryption System that implements three different algorithms: Caesar cipher, XOR encryption, and RSA encryption. The system allows users to encrypt and decrypt messages using any of these methods, providing a basic understanding of these cryptographic techniques.

## Features

- **Caesar Cipher**: A substitution cipher where each letter in the plaintext is shifted a certain number of places down or up the alphabet.
- **XOR Encryption**: A symmetric encryption technique that uses the XOR bitwise operation.
- **RSA Encryption**: An asymmetric encryption technique based on the mathematical properties of prime numbers.

## Technology Stack

- **Programming Language**: C++
- **Development Environment**: Dev C++ (or any compatible C++ IDE)

## Installation

### Prerequisites

- Dev C++ (or any compatible C++ IDE)
- Basic knowledge of C++ programming

### Steps

1. **Clone the Repository**

   ```bash
   git clone https://github.com/denisesaronae/EncryptionDecryption.git
   cd EncryptionDecryption
   ```

2. **Open the Project in Dev C++**

   - Launch Dev C++.
   - Open the `encryption_system.dev` project file.

3. **Build and Run**

   - Build the project by selecting `Execute -> Compile & Run` in the menu.

## Usage

1. **Main Menu**

   Upon running the application, you will be presented with a main menu with the following options:

   - Encrypt a message using Caesar cipher
   - Decrypt a message using Caesar cipher
   - Encrypt a message using XOR encryption
   - Decrypt a message using XOR encryption
   - Encrypt a message using RSA encryption
   - Decrypt a message using RSA encryption
   - Exit

2. **Caesar Cipher**

   - Select the option to encrypt or decrypt using Caesar cipher.
   - Enter the message and the shift value (key).
   - The encrypted or decrypted message will be displayed.

3. **XOR Encryption**

   - Select the option to encrypt or decrypt using XOR encryption.
   - Enter the message and the key.
   - The encrypted or decrypted message will be displayed.

4. **RSA Encryption**

   - Select the option to encrypt or decrypt using RSA encryption.
   - For encryption, enter the plaintext message. The system will generate public and private keys and display the encrypted message.
   - For decryption, enter the encrypted message and the private key. The decrypted message will be displayed.

## File Structure

- **main.cpp**: Main source file containing the implementation of the encryption and decryption methods.
