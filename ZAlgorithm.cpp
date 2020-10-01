#include <iostream>
using namespace std;

void get_z_array(string str, int z[])
{
    int size = str.length();
    int left = 0, right = 0, k;
    int i, j;

    for (i = 1; i < size; i++)
    {

        if (i > right)
        {
            left = i;
            right = i;
            while (right < size && str[right - left] == str[right])
            {
                right++;
            }

            z[i] = right - left;
            right--;
        }
        else
        {
            k = i - left;

            if (z[k] < right - i + 1)
            {
                z[i] = z[k];
            }
            else
            {
                left = i;
                while (right < size && str[right - left] == str[right])
                {
                    right++;
                }
                z[i] = right - left;
                right--;
            }
        }
    }
}

void z_Algorithm(string text, string pattern)
{
    string str = pattern + "$" + text;
    int len = str.length();
    int z[len];
    int i;
    get_z_array(str, z);

    for (i = 0; i < len; i++)
    {
        if (z[i] == pattern.length())
        {
            cout << "Pattern is found at index : " << i - pattern.length() - 1 << endl;
        }
    }
}

int main()
{
    string text, pattern;
    cin >> text;
    cin >> pattern;
    z_Algorithm(text, pattern);

    return 0;
}
