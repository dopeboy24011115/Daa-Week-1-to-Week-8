#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int v, e;
    cin >> v >> e;

    vector<pair<int, int>> graph[v];

    for (int i = 0; i < e; i++)
    {
        int u, w, wt;
        cin >> u >> w >> wt;

        graph[u].push_back({w, wt});
        graph[w].push_back({u, wt});
    }

    int src;
    cin >> src;

    vector<int> dist(v, 1e9);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty())
    {
        int node = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        for (auto it : graph[node])
        {
            int next = it.first;
            int wt = it.second;

            if (d + wt < dist[next])
            {
                dist[next] = d + wt;
                pq.push({dist[next], next});
            }
        }
    }

    for (int i = 0; i < v; i++)
    {
        cout << "Distance to " << i << " = " << dist[i] << endl;
    }

    return 0;
}