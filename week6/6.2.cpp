#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[100];
int color[100];

bool bfs(int start)
{
    queue<int> q;

    q.push(start);
    color[start] = 1;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int next : graph[node])
        {
            if (color[next] == 0)
            {
                color[next] = -color[node];
                q.push(next);
            }
            else if (color[next] == color[node])
            {
                return false;
            }
        }
    }

    return true;
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

    bool bipartite = true;

    for (int i = 0; i < v; i++)
    {
        if (color[i] == 0)
        {
            if (!bfs(i))
            {
                bipartite = false;
                break;
            }
        }
    }

    if (bipartite)
        cout << "Bipartite Graph";
    else
        cout << "Not Bipartite";

    return 0;
}