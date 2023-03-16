#include <iostream>
#include <algorithm>
using namespace std;

int n, k, temp, x;
int* s;

void O (int* s, int* t, int l, int r, int sd)
{
    int key = l;
    int i = key;
    int j = sd + 1;
    while ((i <= sd) && (j <= r))
    {
        if (s[i] <= s[j]) 
        {
            t[key++] = s[i++];
        }
        else 
        {
            t[key++] = s[j++];
        }
    }
    while (i <= sd) 
    {
        t[key++] = s[i++];
    }
    for (int i = l; i <= r; i++) 
    {
        s[i] = t[i];
    }
}

void merge_s(int* s, int* t, int la, int ra)
{
    if (ra > la)
    {
        int sd = la + (ra - la) / 2;
        merge_s(s, t, la, sd);
        merge_s(s, t, sd + 1, ra);
        O(s, t, la, ra, sd);
    }
    else
    {
        cout << 1;
    }
}

string q (int* d, int w)
{
    temp = 0;
    int l = 0;
    int r = n - 1;
    while ((temp != 1) && (l <= r)) 
    {
        if (l == r)
        {
            if (d[l] == w)
            {
                return "YES";
            }
            else
            {
                return "NO";
            }
        }
        if (r - l == 1)
        {
            if (d[l] == w || d[l + 1] == w)
            {
                return "YES";
            }
            else
            {
                return "NO";
            }
        }
        if (r - l == 2)
        {
            if (d[l] == w || d[l + 1] == w || d[l + 2] == w)
            {
                return "YES";
            }
            else
            {
                return "NO";
            }
        }
        x = d[(l + r) / 2];
        if (x == w)
        {
            return "YES";
        }
        if (x < w)
        {
            r = (l + r) / 2 + 1;
        }
        else
        {
            l = (l + r) / 2 - 1;
        }
    }
    if (temp == 1)
    {
        return "YES";
    }
    else
    {
        return "NO";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int u;
    cin >> n >> k;
    s = new int[n];
    int* t = new int[n] {0};
    u = n;
    int* lb = new int[k];
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    //for (int i = 0; i < k; i++)
    //{
    //    //cin >> lb[i];
    //}
    //for (int i = 0; i < k; i++)
    //{
    //    //cout << q(s, lb[i]) << endl;
    //}
    merge_s(s, t, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << s[i] << " ";
    }
}
