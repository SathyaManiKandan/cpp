#include <bits/stdc++.h>
using namespace std;
class Graph
{
public:
    unordered_map<int, list<pair<int, int>>> adj;
    void addEdges(int u, int v, int weight)
    {
        pair<int, int> p = make_pair(v, weight);
        adj[u].push_back(p);
    }
    void dfs(int node, unordered_map<int, bool> &vis, stack<int> s)
    {
        vis[node] = 1;
        for (auto i : adj[node])
        {
            if (!vis[i.first])
            {
                dfs(i.first, vis, s);
            }
        }
        s.push(node);
    }
    void findDistance(vector<int> &distance, stack<int> &s, int src)
    {
        distance[src] = 0;
        while (!s.empty())
        {
            int top = s.top();
            s.pop();
            if (top != INT_MAX)
            {
                for (auto i : adj[top])
                {
                    if (distance[top] + i.second < distance[i.first])
                    {
                        distance[i.first] = distance[i.second] + distance[top];
                    }
                }
            }
        }
    }
    void dfsprint(stack<int> s)
    {
        if (s.empty())
        {
            return;
        }
        cout << s.top() << endl;
        s.pop();
        dfsprint(s);
        return;
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
    unordered_map<int, bool> vis;
    stack<int> s;
    g.dfs(0, vis, s);
    int n = 6;
    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
        // dfsprint(s);
        // return;
    }

    g.dfsprint(s);
    vector<int> distance(n, INT_MAX);
    int src = 1;
    g.findDistance(distance,