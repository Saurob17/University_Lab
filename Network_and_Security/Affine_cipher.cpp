#include <iostream>
#include <string>
#include <cctype>
using namespace std;


string toLower(string text)
{
    for (char &ch : text)
    {
        ch = tolower(ch);
    }

    return text;
}

// Find multiplicative inverse of a modulo 26
int modInverse(int a)
{
    for (int i = 1; i < 26; i++)
    {
        if ((a * i) % 26 == 1)
        {
            return i;
        }
    }

    return -1; // No inverse exists
}


// Encryption
string encrypt(string plaintext, int k1, int k2)
{
    string ciphertext = "";

    plaintext = toLower(plaintext);

    for (char ch : plaintext)
    {
        int P = ch - 'a';

        // C = (P * k1 + k2) mod 26
        int C = (P * k1 + k2) % 26;

        ciphertext += char(C + 'a');
    }

    return ciphertext;
}


// Decryption
string decrypt(string ciphertext, int k1, int k2)
{
    string plaintext = "";

    ciphertext = toLower(ciphertext);

    int inverse = modInverse(k1);

    if (inverse == -1)
    {
        return "Invalid k1: No multiplicative inverse.";
    }

    for (char ch : ciphertext)
    {
        int C = ch - 'a';

        // P = ((C - k2) * k1^-1) mod 26
        int P = ((C - k2 + 26) * inverse) % 26;

        plaintext += char(P + 'a');
    }

    return plaintext;
}


int main()
{
    string plaintext;
    int k1, k2;

  
    cin >> plaintext;

  
    cin >> k1;

    cout << "Enter k2: ";
    cin >> k2;


  
    if (modInverse(k1) == -1)
    {
        cout << "Invalid k1!" << endl;
        cout << "k1 must have a multiplicative inverse modulo 26." << endl;
        return 0;
    }


    
    string ciphertext = encrypt(plaintext, k1, k2);

    cout << "\nCiphertext: " << ciphertext << endl;


    
    string decryptedText = decrypt(ciphertext, k1, k2);

    cout << "Decrypted : " << decryptedText << endl;


    return 0;
}