#include <iostream>
#include <string>
using namespace std;

string encryptVigenere(string plaintext, string key)
{
    string ciphertext = "";
    int keyIndex = 0;

    for (char ch : plaintext)
    {
        if (ch >= 'A' && ch <= 'Z')
        {
            int plainValue = ch - 'A';
            int keyValue = key[keyIndex % key.length()] - 'A';

            int cipherValue = (plainValue + keyValue) % 26;

            ciphertext += char(cipherValue + 'A');

            keyIndex++;
        }
    }

    return ciphertext;
}

string decryptVigenere(string ciphertext, string key)
{
    string plaintext = "";
    int keyIndex = 0;

    for (char ch : ciphertext)
    {
        if (ch >= 'A' && ch <= 'Z')
        {
            int cipherValue = ch - 'A';
            int keyValue = key[keyIndex % key.length()] - 'A';

            int plainValue = (cipherValue - keyValue + 26) % 26;

            plaintext += char(plainValue + 'A');

            keyIndex++;
        }
    }

    return plaintext;
}

int main()
{
    string plaintext, key;

    cout << "Enter plaintext: ";
    cin >> plaintext;

    cout << "Enter key: ";
    cin >> key;

    // Convert plaintext and key to uppercase
    for (char &ch : plaintext)
        ch = toupper(ch);

    for (char &ch : key)
        ch = toupper(ch);

    string ciphertext = encryptVigenere(plaintext, key);
    string decryptedText = decryptVigenere(ciphertext, key);

    cout << "\nPlaintext  : " << plaintext;
    cout << "\nKey        : " << key;
    cout << "\nCiphertext : " << ciphertext;
    cout << "\nDecrypted  : " << decryptedText;

    return 0;
}