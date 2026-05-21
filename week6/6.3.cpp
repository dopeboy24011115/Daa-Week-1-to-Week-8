#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[100];
bool visited[100];
bool recStack[100];

bool dfs(int node)
{
    visited[node] = true;
    recStack[node] = true;

    for (int next : graph[node])
    {
        if (!visited[next])
        {
            if (dfs(next))
                return true;
        }
        else if (recStack[next])
        {
            return true;
        }
    }

    recStack[node] = false;

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
    }

    bool cycle = false;

    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            if (dfs(i))
            {
                cycle = true;
                break;
            }
        }
    }

    if (cycle)
        cout << "Cycle Exists";
    else
        cout << "No Cycle";

    return 0;
}