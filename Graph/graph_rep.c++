#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        // for unidirected graph these two are used
        // for directed graph only one is used
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    return 0;
}