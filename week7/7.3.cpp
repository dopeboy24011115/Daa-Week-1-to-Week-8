#include <iostream>
using namespace std;

#define INF 100000

int shortestPath(int graph[100][100], int u, int v, int k, int V)
{
    if (k == 0 && u == v)
        return 0;

    if (k == 1 && graph[u][v] != INF)
        return graph[u][v];

    if (k <= 0)
        return INF;

    int ans = INF;

    for (int i = 0; i < V; i++)
    {
        if (graph[u][i] != INF && u != i && v != i)
        {
            int temp = shortestPath(graph, i, v, k - 1, V);

            if (temp != INF)
                ans = min(ans, graph[u][i] + temp);
        }
    }

    return ans;
}

int main()
{
    int V, E;
    cin >> V >> E;

    int graph[100][100];

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            graph[i][j] = INF;
        }
    }

    for (int i = 0; i < E; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;

        graph[u][v] = wt;
    }

    int src, dest, k;
    cin >> src >> dest >> k;

    int ans = shortestPath(graph, src, dest, k, V);

    if (ans == INF)
        cout << "No Path";
    else
        cout << ans;

    return 0;
}