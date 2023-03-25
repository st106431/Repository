#include <iostream>
#include <string>
using namespace std;

void bin(double t, string & s)
{
    union
    {
        double t;
        long long i;
    } un;
    un.t = t;
    for (long long i = 0; i <= 63; i++)
    {
        if ((un.i % 2) == 1)
        {
            s.push_back('1');
        }
        else
        {
            s.push_back('0');
        }
        un.i >>= 1;
    }
}

union share
{
    double as_double;
    unsigned char as_arr[8];
};

int main()
{
    double a, b, t;
    string sc;
    volatile share s;
    cin >> a >> b;
    t = a / b;
    s.as_double = t;
    bin(abs(t), sc);
    for (int i = 63; i >= 0; i--)
    {
        if (i == 63)
        {
            if (t >= 0)
            {
                cout << 0;
            }
            else
            {
                cout << 1;
            }
        }
        else
        {
            if ((i != 8) && (i != 16) && (i != 24) && (i != 32) && (i != 40) && (i != 48) && (i != 56))
            {
                cout << sc[i];
            }
            else
            {
                cout << sc[i] << " ";
            }
        }
    }
    cout << endl;
    for (int i = 7; i >= 0; i--)
    {
        printf("%02X ", s.as_arr[i]);
    }
    return 0;
}