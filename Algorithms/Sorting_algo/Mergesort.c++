#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int start, int mid, int end)
{
    int i = start;
    int j = mid + 1;
    int k = 0;
    int sz = end - start + 1;
    vector<int> temp(sz);
    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }
    while (j <= end)
    {
        temp[k++] = arr[j++];
    }
    for (int t = 0; t < sz; t++)
    {
        arr[t + start] = temp[t];
    }
}

void mergesort(vector<int> &arr, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        mergesort(arr, start, mid);
        mergesort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

int main()
{
    vector<int> arr = {9, 0, -3, -2, 2, 1, 6, 7};
    mergesort(arr, 0, 7);
    for (int t = 0; t < arr.size(); t++)
    {
        cout << arr[t] << " ";
    }
    cout << endl;
}