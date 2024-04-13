#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> getSecondOrderElements(int n, vector<int> a)
{
    // Write your code here.
    vector<int> res;
    int l = INT_MIN;
    int s = INT_MAX;
    int ss = INT_MAX;
    int sl = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        l = max(l, a[i]);
        s = min(s, a[i]);
    }
    for (int j = 0; j < n; j++)
    {
        if (a[j] > sl && a[j] != l)
        {
            sl = a[j];
        }
        if (a[j] < ss && a[j] != s)
        {
            ss = a[j];
        }
    }
    res.push_back(sl);
    res.push_back(ss);

    return res;
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<int> result = getSecondOrderElements(n, a);
    cout << "Second largest element: " << result[0] << endl;
    cout << "Second smallest element: " << result[1] << endl;

    return 0;
}
