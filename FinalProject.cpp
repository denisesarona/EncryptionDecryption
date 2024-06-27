#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void printTabs(int tabNum) // FUNCTION TO ADD TABS
{
    for (int i = 0; i < tabNum; ++i) 
    {
        cout<<"\t";
    }
}

void clearScreen() // FUNCTION TO CLEAR SCREEN
{
    cout<<"\033[2J\033[1;1H";
}

// Function to perform Caesar cipher encryption
string caesarCipherEncrypt(string plaintext, int shift) {
    string ciphertext = "";
    for (char& c : plaintext) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            c = base + (c - base + shift) % 26;
        }
        ciphertext += c;
    }
    return ciphertext;
}

// Function to perform Caesar cipher decryption
string caesarCipherDecrypt(string ciphertext, int shift) {
    return caesarCipherEncrypt(ciphertext, 26 - shift); // Decrypting Caesar cipher by shifting in opposite direction
}

// Function to perform XOR encryption
string xorEncrypt(string plaintext, string key) {
    string ciphertext = "";
    for (size_t i = 0; i < plaintext.length(); ++i) {
        ciphertext += plaintext[i] ^ key[i % key.length()];
    }
    return ciphertext;
}

// Function to perform XOR decryption
string xorDecrypt(string ciphertext, string key) {
    return xorEncrypt(ciphertext, key); // XOR decryption is its own inverse operation
}

// Function to perform RSA encryption (simplified)
long long modularExponentiation(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

// Function to perform RSA decryption (simplified)
long long rsaDecrypt(long long ciphertext, long long rsaD, long long rsaN) {
    return modularExponentiation(ciphertext, rsaD, rsaN); // RSA decryption using modular exponentiation
}

// Function to perform combined encryption
string combinedEncryption(string plaintext, int caesarShift, string xorKey, long long rsaN, long long rsaE) {
    // Step 1: Apply Caesar Cipher Encryption
    string caesarEncrypted = caesarCipherEncrypt(plaintext, caesarShift);

    // Step 2: Apply XOR Encryption to the Caesar encrypted text
    string xorEncrypted = xorEncrypt(caesarEncrypted, xorKey);

    // Step 3: Apply RSA Encryption to the XOR encrypted text
    string rsaEncrypted = "";
    for (char c : xorEncrypted) {
        long long m = static_cast<long long>(c);
        long long crypted = modularExponentiation(m, rsaE, rsaN);
        rsaEncrypted += to_string(crypted) + " ";
    }

    return rsaEncrypted;
}

// Function to perform combined decryption
string combinedDecryption(string encryptedMessage, int caesarShift, string xorKey, long long rsaN, long long rsaD) {
    // Step 1: Decrypt RSA Encryption
    string rsaDecrypted = "";
    size_t pos = 0;
    while ((pos = encryptedMessage.find(' ')) != string::npos) {
        string token = encryptedMessage.substr(0, pos);
        long long ciphertext = stoll(token);
        long long decrypted = rsaDecrypt(ciphertext, rsaD, rsaN);
        rsaDecrypted += static_cast<char>(decrypted);
        encryptedMessage.erase(0, pos + 1);
    }

    // Step 2: Decrypt XOR Encryption
    string xorDecrypted = xorDecrypt(rsaDecrypted, xorKey);

    // Step 3: Decrypt Caesar Cipher Encryption
    string caesarDecrypted = caesarCipherDecrypt(xorDecrypted, caesarShift);

    return caesarDecrypted;
}

int main() {
    bool continueLoop = true;

    while (continueLoop) {
        // Example input
        string plaintext;
        int caesarShift;
        string xorKey;
        long long rsaN = 3233; // RSA modulus (n)
        long long rsaE = 17;   // RSA public exponent (e)
        long long rsaD = 2753; // RSA private exponent (d)

        // Get user input
        clearScreen();
        cout << R"(
                _______  _______  _______           _______  _______  _______  _______
                (  ____ \(  ___  )(  ____ \|\     /|(  ___  )(  ____ )(  ____ \(  ___  )
                | (    \/| (   ) || (    \/( \   / )| (   ) || (    )|| (    \/| (   ) |
                | |      | (___) || (__     \ (_) / | |   | || (____)|| (_____ | (___) |
                | |      |  ___  ||  __)     ) _ (  | |   | ||     __)(_____  )|  ___  |
                | |      | (   ) || (       / ( ) \ | |   | || (\ (         ) || (   ) |
                | (____/\| )   ( || (____/\( /   \ )| (___) || ) \ \__/\____) || )   ( |
                (_______/|/     \|(_______/|/     \|(_______)|/   \__/\_______)|/     \|
                            Caesar cypher, XOR Algorithm, and RSA Algorithm
        )" << endl;


        cout<<endl;
        printTabs(5); cout << "Enter plaintext: ";
        getline(cin, plaintext);

        printTabs(5); cout << "Enter Caesar shift (integer): ";
        cin >> caesarShift;

        printTabs(5); cout << "Enter XOR key: ";
        cin.ignore(); // Clear input buffer
        getline(cin, xorKey);

        // Perform combined encryption
        string encryptedMessage = combinedEncryption(plaintext, caesarShift, xorKey, rsaN, rsaE);

        clearScreen();

        cout<<"\033[97m";
        cout<<"\033[42m";
        printTabs(5); cout<<"                                                           "<<endl;
        printTabs(5); cout<<"                     Encryption Process                    "<<endl;
        printTabs(5); cout<<"                                                           \033[0m"<<endl;
        cout<<endl;
        printTabs(5); cout<< "  Plaintext: " << plaintext << endl;
        printTabs(5); cout<< "  Caesar Shift: " << caesarShift << endl;
        printTabs(5); cout<< "  XOR Key: " << xorKey << endl;
        printTabs(5); cout<< "  RSA Modulus (n): " << rsaN << endl;
        printTabs(5); cout<< "  RSA Public Exponent (e): " << rsaE << endl;
        printTabs(5); cout<< "  Encrypted Message: " << encryptedMessage << endl;

        cout<<endl;
        cout<<"\033[97m";
        cout<<"\033[42m";
        printTabs(5); cout<<"                                                           "<<endl;
        printTabs(5); cout<<"                     Decryption Process                    "<<endl;
        printTabs(5); cout<<"                                                           \033[0m"<<endl;
        cout<<endl;
        string decryptedMessage = combinedDecryption(encryptedMessage, caesarShift, xorKey, rsaN, rsaD);
        printTabs(5); cout<< "  Encrypted Message: "<<encryptedMessage<<endl;
        printTabs(5); cout<< "  Caesar Shift: "<<caesarShift<<endl;
        printTabs(5); cout<< "  XOR Key: "<<xorKey<<endl;
        printTabs(5); cout<< "  RSA Modulus (n): "<<rsaN <<endl;
        printTabs(5); cout<< "  RSA Private Exponent (d): "<<rsaD<<endl;
        printTabs(5); cout<< "  Decrypted Message: "<<decryptedMessage<<endl;

        // Ask user if they want to continue
        char choice;
        cout<<endl;
        printTabs(5); cout << "  Do you want to encrypt and decrypt again? (y/n): ";
        cin >> choice;

        if (choice != 'y' && choice != 'Y') {
            continueLoop = false;
        }

        cin.ignore(); // Clear input buffer before looping
    }

    return 0;
}
