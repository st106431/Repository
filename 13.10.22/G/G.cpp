#include <iostream>
#include <string>
using namespace std;

void bin(float t, string & s)
{
    union 
    {
        float t; 
        int i; 
    } un;
    un.t = t;
    for (int i = 0; i <= 31; i++)
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
    float as_float;
    unsigned char as_arr[4];
};

int main()
{
    float a, b, t;
    string sc;
    volatile share s;
    cin >> a >> b;
    t = a / b;
    s.as_float = t;
    bin(abs(t), sc);
    for (int i = 31; i >= 0; i--)
    {
        if (i == 31)
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
            if ((i != 8) && (i != 16) && (i != 24))
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
    for (int i = 3; i >= 0; i--)
    {
        printf("%02X ", s.as_arr[i]);
    }
    return 0;
}