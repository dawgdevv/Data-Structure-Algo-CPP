
#include <bits/stdc++.h>
#include <string>
#include <algorithm>
using namespace std;
/*
Time complexity=log(n) in base 2.
space complexity=log(n) in base 2.
*/
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
/*
Time complexity=O(len).
space complexity=O(1).
*/
int convert_2int(string n)
{
    int len = n.length();
    int num = 0;
    int p2 = 1;
    for (int i = len - 1; i >= 0; i--)
    {
        if (n[i] == '1')
        {
            num = num + p2;
        }
        p2 = p2 * 2;
    }
    return num;
}
int main()
{
    int n;
    cout << "input the number" << endl;
    cin >> n;
    string res = convert_2binary(n);
    cout << "The conversion is: " << res << endl;
    string bin;
    cout << "input the binary num" << endl;
    cin >> bin;
    int res_d = convert_2int(bin);
    cout << "The conversion in dec is: " << res_d << endl;
}