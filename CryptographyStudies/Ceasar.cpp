#include <iostream>
#include <string>
using namespace std;

string Ceasar_Encrypt(string_view text, const int shift)
{
    string str;
    str.reserve(text.length());
    for (const auto c : text)
    {
        if (isalpha(c) && isupper(c))
        {
            str += 'A' + (c - 'A' + shift) % 26;
        }
        else
        {
            str += c;
        }
    }

    return str;
}

string Ceasar_Decrypt(string_view text, const int shift)
{
    string str;
    str.reserve(text.length());
    for (const auto c : text)
    {
        if (isalpha(c) && isupper(c))
        {
            str += 'A' + (26 + c - 'A' - shift) % 26;
        }
        else
        {
            str += c;
        }
    }

    return str;
}

int main()
{
    auto text = "ABC";

    cout << Ceasar_Encrypt(text, 2);
    cout << Ceasar_Decrypt(text, 2);
    return 0;
}