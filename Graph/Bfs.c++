#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// Time complexity: O(V+E)
// why it is better to use adjacency list over adjacency matrix beacause in adjacency list we can easily find the adjacent nodes of a node in O(1) time
vector<int> bfs(int v, vector<int> adj[], int n)
{
    int visted[n] = {0};
    vector<int> bfs;
    queue<int> q;
    q.push(v);
    visted[v] = 1;
    // while queue is not empty
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        bfs.push_back(u);
        // for all the adjacent nodes of u
        for (int i = 0; i < adj[u].size(); i++)
        {
            if (visted[adj[u][i]] == 0)
            {
                q.push(adj[u][i]);
                visted[adj[u][i]] = 1;
            }
        }
    }
    return bfs;
}

int main()
{
    // n = number of nodes, m = number of edges
    int n, m;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;
    vector<int> adj[n];
    for (int i = 0; i < m; i++)
    {
        // u, v are the nodes
        int u, v;
        cout << "Enter the nodes: ";
        cin >> u >> v;
        // adding edge
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> bfs_traversal = bfs(0, adj, n);
    cout << "BFS Traversal: ";
    for (int i = 0; i < bfs_traversal.size(); i++)
    {
        cout << bfs_traversal[i] << " ";
    }
    return 0;
}