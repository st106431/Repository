#include <iostream>
#include <algorithm>
using namespace std;

void out(int number)
{
    if (number % 2 == 0)
    {
        cout << number / 2;
    }
    else
    {
        double a = number / 2 + 0.5;
        cout << a;
    }
}

int main()
{
    int n = 0;
    cin >> n;
    int* s = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    sort(s, s + n);
    if (n % 2 == 0)
    {
        cout.precision(12);
        out(s[(n - 1) / 2] + s[(n + 1) / 2]);
    }
    else
    {
        cout << s[(n - 1) / 2];
    }
}
