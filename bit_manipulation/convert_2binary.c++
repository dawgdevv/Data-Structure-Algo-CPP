#include <bits/stdc++.h>
#include <string>
#include <algorithm>
using namespace std;

string convert_2binary(int n)
{
    string r = " ";
    while (n != 0)
    {
        if (n % 2 == 1)
        {
            r += '1';
        }
        else
            r += '0';
        n = n / 2;
    }
    reverse(r.begin(), r.end());
    return r;
}

int main()
{
    int n;
    cout << "input the number" << endl;
    cin >> n;
    string res = convert_2binary(n);
    cout << "The conversion is: " << res << endl;
}