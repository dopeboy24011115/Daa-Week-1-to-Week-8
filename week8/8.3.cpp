#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge
{
    int u, v, wt;
};

bool cmp(Edge a, Edge b)
{
    return a.wt > b.wt;
}

int parent[100];

int find(int x)
{
    if (parent[x] == x)
        return x;

    return parent[x] = find(parent[x]);
}

void unite(int a, int b)
{
    parent[find(a)] = find(b);
}

int main()
{
    int V, E;
    cin >> V >> E;

    vector<Edge> edges(E);

    for (int i = 0; i < E; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].wt;
    }

    sort(edges.begin(), edges.end(), cmp);

    for (int i = 0; i < V; i++)
        parent[i] = i;

    int cost = 0;

    for (auto e : edges)
    {
        if (find(e.u) != find(e.v))
        {
            unite(e.u, e.v);
            cost += e.wt;
        }
    }

    cout << "Maximum Cost = " << cost;

    return 0;
}