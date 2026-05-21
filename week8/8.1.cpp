#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int V, E;
    cin >> V >> E;

    vector<pair<int, int>> graph[V];

    for (int i = 0; i < E; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;

        graph[u].push_back({v, wt});
        graph[v].push_back({u, wt});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<bool> visited(V, false);

    pq.push({0, 0});

    int cost = 0;

    while (!pq.empty())
    {
        int wt = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (visited[node])
            continue;

        visited[node] = true;
        cost += wt;

        for (auto it : graph[node])
        {
            if (!visited[it.first])
            {
                pq.push({it.second, it.first});
            }
        }
    }

    cout << "Minimum Cost = " << cost;

    return 0;
}