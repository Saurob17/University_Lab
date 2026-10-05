#include<bits/stdc++.h>
using namespace std;

string toLower(string text)
{
    for (char &ch : text)
        ch = tolower(ch);

    return text;
}

int modInverse(int key)
{
    for (int i = 1; i < 26; i++)
    {
        if ((key * i) % 26 == 1)
            return i;
    }

    return -1;
}

string encrypt(string text, int key)
{
    string result = "";

    for (char ch : text)
    {
        int P = ch - 'a';
        int C = (P * key) % 26;

        result += char(C + 'a');
    }

    return result;
}

string decrypt(string text, int key)
{
    string result = "";
    int inverse = modInverse(key);

    for (char ch : text)
    {
        int C = ch - 'a';
        int P = (C * inverse) % 26;

        result += char(P + 'a');
    }

    return result;
}

int main()
{
    string text;
    int key;

    getline(cin, text);
    cin >> key;

    text = toLower(text);

    int inverse = modInverse(key);

    if (inverse == -1)
    {
        cout << "Invalid key!" << endl;
        return 0;
    }

    stringstream ss(text);
    string word;
    string ciphertext = "";

    while (ss >> word)
    {
        ciphertext += encrypt(word, key) + " ";
    }

    ciphertext.pop_back();

    cout << "Ciphertext: " << ciphertext << endl;

    stringstream ss2(ciphertext);
    string decrypted = "";

    while (ss2 >> word)
    {
        decrypted += decrypt(word, key) + " ";
    }

    decrypted.pop_back();

    cout << "Decrypted: " << decrypted << endl;

    return 0;
}