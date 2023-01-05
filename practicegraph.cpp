#include <bits/stdc++.h>
using namespace std;
class Graph
{
public:
    unordered_map<int, list<pair<int, int>>> adj;
    void addEdges(int u, int v, int weight)
    {
        adj[u].push_back(make_pair(v, weight));
    }
    void dfs(stack<int> &s, int node, unordered_map<int, bool> &vis)
    {
        vis[node] = true;
        for (auto i : adj[node])
        {
            if (!vis[i.first])
            {
                dfs(s, i.first, vis);
            }
        }
        s.push(node);
    }
    void getDistance(vector<int> &distance, stack<int> &s, int src)
    {
        distance[src] = 0;
        while (!s.empty())
        {
            int top = s.top();
            s.pop();
            if (distance[top] != INT_MAX)
            {
                for (auto i : adj[top])
                {
                    if (i.second + distance[top] < distance[i.first])
                    {
                        distance[i.first] = i.second + distance[top];
                    }
                }
            }
        }
    }
};
int main()
{
    Graph g;
    g.addEdges(0, 1, 5);
    g.addEdges(0, 2, 3);
    g.addEdges(1, 2, 2);
    g.addEdges(1, 3, 6);
    g.addEdges(2, 3, 7);
    g.addEdges(2, 4, 4);
    g.addEdges(2, 5, 2);
    g.addEdges(3, 4, -1);
    g.addEdges(4, 5, -2);
    stack<int> s;
    unordered_map<int, bool> vis;
    int n = 6;
    int src = 1;
    g.dfs(s, 0, vis);
    vector<int> distance(n, INT_MAX);
    g.getDistance(distance, s, src);
    for (int i = 0; i < n; i++)
    {
        cout << distance[i] << endl;
    }
}