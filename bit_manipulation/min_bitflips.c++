#include <iostream>
int flipBits(int A, int B)
{
    // Write your code here.
    int flip = A ^ B;
    int count = 0;
    for (int i = 0; i < 31; i++)
    {
        if (flip & (1 << i))
        {
            count++;
        }
    }
    return count;
}
int main()
{
    int c = flipBits(18, 11);
    std::cout << c << std::endl;
}
