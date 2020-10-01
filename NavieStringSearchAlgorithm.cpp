#include <iostream>
using namespace std;

void naive_algorithm(string text, string pattern)
{

    int text_len = text.length();
    int pattern_len = pattern.length();
    int i, j, flag = 0;
    for (i = 0; i < text_len; i++)
    {
        for (j = 0; j < pattern_len; j++)
        {
            if (text[i + j] != pattern[j])
            {

                break;
            }
        }
        if (j == pattern_len)
        {
            flag = 1;
        }
    }
    if (flag == 1)
    {
        cout << "Pattern is present in the loop at index : " << i;
    }
    else
    {
        cout << "Pattern is not present";
    }
}

int main()
{
    string text, pattern;
    cin >> text;
    cin >> pattern;
    naive_algorithm(text, pattern);
    return 0;
}