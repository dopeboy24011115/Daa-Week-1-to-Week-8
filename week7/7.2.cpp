#include <iostream>
#include <vector>
using namespace std;

struct Edge
{
    int u, v, wt;
};

int main()
{
    int V, E;
    cin >> V >> E;

    vector<Edge> edges(E);

    for (int i = 0; i < E; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].wt;
    }

    int src;
    cin >> src;

    vector<int> dist(V, 1e9);

    dist[src] = 0;

    for (int i = 1; i < V; i++)
    {
        for (auto e : edges)
        {
            if (dist[e.u] != 1e9 && dist[e.u] + e.wt < dist[e.v])
            {
                dist[e.v] = dist[e.u] + e.wt;
            }
        }
    }

    for (auto e : edges)
    {
        if (dist[e.u] != 1e9 && dist[e.u] + e.wt < dist[e.v])
        {
            cout << "Negative Cycle Exists";
            return 0;
        }
    }

    for (int i = 0; i < V; i++)
    {
        cout << "Distance to " << i << " = " << dist[i] << endl;
    }

    return 0;
}