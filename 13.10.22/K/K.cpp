#include <iostream>
using namespace std;

int main()
{
	int t, copy;
	cin >> t;
    int* s = new int[32];
    copy = t;
    for (int i = 31; i >= 0; i--)
    {
        s[31 - i] = copy % 2;
        copy /= 2;
    }
    cout << s[27] << endl;
    if (s[16] == 0)
    {
        int sum = 0;
        for (int i = 15; i >= 0; i--)
        {
            if (i != 0)
            {
                sum += s[i] * (2 ^ i);
                cout << sum << endl;
            }
            else
            {
                sum += s[0];
            }
        }
        cout << sum;
        return 0;
    }
    else
    {

    }
}