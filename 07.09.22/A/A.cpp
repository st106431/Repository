#include <iostream>

int main()
{
    int a, b, d, t;
    std::cin >> a >> b >> d;
    if (d < abs(a - b))
    {
        if (b >= a)
        {
            t = a + d;
        }
        else
        {
            t = a - d;
        }
    }
    else
    {
        t = b;
    }
    std::cout << t;
}