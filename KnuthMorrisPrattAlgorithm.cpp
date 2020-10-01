#include <iostream>
using namespace std;

void compute_lps_array(string pattern, int pattern_len, int lps[])
{
    int len = 0; // to know length of previous lps
    lps[0] = 0;
    int i = 1;

    while (i < pattern_len)
    {
        if (pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void kmp_algorithm(string text, string pattern)
{
    int text_len = text.length();
    int pattern_len = pattern.length();
    int flag = 0;
    //create an array to store longest suffix and prefix value
    int lps[pattern_len];

    //compute lps array
    compute_lps_array(pattern, pattern_len, lps);
    int i = 0;
    int j = 0;

    while (i < text_len)
    {
        // if both the characters are equals increment both i and j
        if (text[i] == pattern[j])
        {
            i++;
            j++;
        }
        if (j == pattern_len)
        {
            cout << "Pattern found at index : " << i - j << endl;
            j = lps[j - 1];
        }
        else if (i < text_len && text[i] != pattern[j]) // when characters are not equals
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
}

int main()
{
    string text, pattern;
    cin >> text;
    cin >> pattern;
    kmp_algorithm(text, pattern);
    return 0;
}