#include <iostream>
using namespace std;

union share
{
    int as_int;
    unsigned char as_arr[4];
};

int main()
{
    int t;
    volatile share s;
    cin >> t;
    s.as_int = t;
    for (int i = 31; i >= 0; i--)
    {
        if (i == 8 || i == 16 || i == 24)
        {
            cout << ((t >> i) & 1) << " ";
        }
        else
        {
            cout << ((t >> i) & 1);
        }
    }
    cout << endl;
    for (int i = 3; i >= 0; i--)
    {
        printf("%02X ", s.as_arr[i]);
    }
    return 0;
}