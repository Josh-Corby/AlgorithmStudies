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

string Build_Vignere_Table()
{
    string table;
    table.reserve(26 * 26);
    for (int i = 0; i < 26; ++i)
    {
        table += Ceasar_Encrypt("ABCDEFGHIJKLMNOPQRSTUVWXYZ", i);
    }

    return table;
}

string Vignere_Encrypt(string_view text, string_view key)
{
    string result;
    result.reserve(text.length());
    static auto table = Build_Vignere_Table();

    for (size_t i = 0; i < text.length(); ++i)
    {
        auto row = key[i % key.length()] - 'A';
        auto col = text[i] - 'A';

        result += table[row * 26 + col];
    }

    return result;
}

string Vignere_Decrypt(string_view text, string_view key)
{
    string result;
    result.reserve(text.length());
    static auto table = Build_Vignere_Table();

    for (size_t i = 0; i < text.length(); ++i)
    {
        auto row = key[i % key.length()] - 'A';

        for (size_t col = 0; col < 26; ++col)
        {
            if (table[(row * 26) + col] == text[i])
            {
                result += 'A' + col;
                break;
            }
        }
    }

    return result;
}

int main()
{
    auto text = "THECPPCHALLENGER";
    auto enc = Vignere_Encrypt(text, "SAMPLE");
    auto dec = Vignere_Decrypt(enc, "SAMPLE");

    cout << text << endl;
    cout << enc << endl;
    cout << dec << endl;


    return 0;
}