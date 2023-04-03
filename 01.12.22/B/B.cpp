#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int const infinity = 1E9 + 1;

int main() 
{
    int n, m;
    cin >> n >> m;
    vector <vector <int> > adj(n);
    for (int j = 0; j < m; j++) 
    {
        int u, v;
        cin >> u >> v;
        u -= 1;
        v -= 1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector <int> d(n, infinity);
    queue <int> q;
    d[0] = 0;
    q.push(0);
    while (!q.empty()) 
    {
        auto v = q.front();
        q.pop();
        cout << v + 1 << ": " << d[v] << endl;
        for (auto u : adj[v]) 
        {
            if (d[u] == infinity) 
            {
                d[u] = d[v] + 1;
                q.push(u);
            }
        }
    }

}