#include <iostream>
using namespace std;

#define SIZE 100000
int arr[SIZE * 2];

string convert_the_string(string s)
{
    string newString = "@";
    for (int i = 0; i < s.size(); i++)
    {
        newString = newString + "#" + s.substr(i, 1);
    }
    newString = newString + "#$";
    return newString;
}

string Manachers_algorithm(string s)
{
    string str = convert_the_string(s);

    int center = 0, end = 0;
    //iterating the characters
    for (int i = 1; i < str.size() - 1; i++)
    {
        int mirror = center - (i - center);

        if (end > i)
        {
            arr[i] = min(end - i, arr[mirror]);
        }
        // comparing the characters
        while (str[i + 1 + arr[i]] == str[i - 1 - arr[i]])
        {
            arr[i]++;
        }
        // change the center and the end value
        if (i + arr[i] > end)
        {
            center = i;
            end = i + arr[i];
        }
    }

    int max_palindrome = 0;
    int center_index = 0;

    for (int i = 1; i < str.size(); i++)
    {
        if (arr[i] > max_palindrome)
        {
            max_palindrome = arr[i];
            center_index = i;
        }
    }
    return s.substr((center_index - 1 - max_palindrome) / 2, max_palindrome);
}

int main()
{
    string s = "";
    cin >> s;
    cout << Manachers_algorithm(s);

    return 0;
}