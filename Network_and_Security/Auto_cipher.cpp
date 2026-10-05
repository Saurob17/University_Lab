#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string lowerCase(string s)
{
    for (char &c : s)
        c = tolower(c);

    return s;
}

string encrypt(string text, int key)
{
    string result = "";
    text = lowerCase(text);

    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] == ' ')
        {
            result += ' ';
            continue;
        }

        int k;

        if (i == 0)
            k = key;
        else
        {
            int j = i - 1;

            while (j >= 0 && text[j] == ' ')
                j--;

            k = text[j] - 'a';
        }

        int p = text[i] - 'a';
        int c = (p + k) % 26;

        result += char(c + 'a');
    }

    return result;
}

string decrypt(string text, int key)
{
    string result = "";

    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] == ' ')
        {
            result += ' ';
            continue;
        }

        int k;

        if (i == 0)
            k = key;
        else
        {
            int j = i - 1;

            while (j >= 0 && result[j] == ' ')
                j--;

            k = result[j] - 'a';
        }

        int c = text[i] - 'a';
        int p = (c - k + 26) % 26;

        result += char(p + 'a');
    }

    return result;
}

int main()
{
    string text;
    int key;

    getline(cin, text);
    cin >> key;

    string cipher = encrypt(text, key);

    cout << "Ciphertext: " << cipher << endl;
    cout << "Decrypted: " << decrypt(cipher, key) << endl;

    return 0;
}