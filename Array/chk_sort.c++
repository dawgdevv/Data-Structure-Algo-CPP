#include <iostream>
#include <vector>

bool isSorted(const std::vector<int> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    std::vector<int> arr = {1, 2, 3, 4, 5};

    if (isSorted(arr))
    {
        std::cout << "Array is sorted." << std::endl;
    }
    else
    {
        std::cout << "Array is not sorted." << std::endl;
    }

    return 0;
}