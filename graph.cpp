#include <bits/stdc++.h>
using namespace std;
class Graph
{
public:
    unordered_map<int, list<int>> adj;

    void addedge(int u, int v, bool dirn)
    {
        adj[u].push_back(v);
        // dirn ==0 implies undirected graph
        if (dirn == 0)
        {
            adj[v].push_back(u);
        }
        void printlist()
        {
            for (auto i : adj)
            {
                cout << "->";
                for (auto j : i.second)
                {
                    cout << j;
                }
            }
        }
    }
};
int main()
{
    Graph g;
    int n;
    cout << "Enter number of Nodes" << endl;
    cin >> n;

    int m;
    cout << "Enter number of edjes" << endl;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u;
        cin >> v;
        g.addedge(u, v, 0);
    }
}