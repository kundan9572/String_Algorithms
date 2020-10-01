#include <iostream>
using namespace std;

#define d 256

void rabin_karp(string text, string pattern, int prime)
{
    int text_len = text.length();
    int pattern_len = pattern.length();

    int i, j, hash_p = 0; // hash_p is hash value of pattern

    int hash_t = 0; // hash_t is hash value of text
    int h = 1;
    int flag = 0;
    for (i = 0; i < pattern_len - 1; i++)
    {
        h = (h * d) % prime;
    }

    // calculating hash value for pattern and text

    for (i = 0; i < pattern_len; i++)
    {
        hash_p = (d * hash_p + pattern[i]) % prime;
        hash_t = (d * hash_t + text[i]) % prime;
    }

    for (i = 0; i <= text_len - pattern_len; i++)
    {
        //check hash value for pattern and text

        if (hash_t == hash_p)
        {
            for (j = 0; j < pattern_len; j++)
            {
                if (text[i + j] != pattern[j])
                {
                    break;
                }
            }
            // pattern is present in the given text
            if (j == pattern_len)
            {
                flag = 1;
                break;
            }
        }
        if (i < text_len - pattern_len)
        {
            hash_t = (d * (hash_t - text[i] * h) + text[i + pattern_len]) % prime;
            // in case if we get negative value then converting in positive
            if (hash_t < 0)
            {
                hash_t = hash_t + prime;
            }
        }
    }
    if (flag == 1)
    {
        cout << "Pattern is present in the given text at index :" << i << endl;
    }
    else
    {
        cout << "Pattern is not present in the text" << endl;
    }
}

int main()
{
    string text, pattern;
    cin >> text;
    cin >> pattern;
    int prime = 37;
    rabin_karp(text, pattern, prime);
    return 0;
}