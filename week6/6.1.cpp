#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[100];
bool visited[100];

bool dfs(int node, int dest)
{
    if (node == dest)
        return true;

    visited[node] = true;

    for (int next : graph[node])
    {
        if (!visited[next])
        {
            if (dfs(next, dest))
                return true;
        }
    }

    return false;
}

int main()
{
    int v, e;
    cin >> v >> e;

    for (int i = 0; i < e; i++)
    {
        int u, w;
        cin >> u >> w;

        graph[u].push_back(w);
        graph[w].push_back(u);
    }

    int src, dest;
    cin >> src >> dest;

    if (dfs(src, dest))
        cout << "Path Exists";
    else
        cout << "No Path";

    return 0;
}