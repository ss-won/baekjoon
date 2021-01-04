#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#define MAX 101
using namespace std;
int v, e, a, b, res = 0;
bool visited[MAX];
vector<int> adj[MAX];
queue<int> q;

void bfs()
{
    q.push(1);
    visited[1] = true;
    while (!q.empty())
    {
        a = q.front();
        q.pop();
        for (auto i = 0; i < adj[a].size(); i++)
        {
            if (!visited[adj[a][i]])
            {
                q.push(adj[a][i]);
                visited[adj[a][i]] = true;
                res++;
            }
        }
    }
    cout << res;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> v >> e;
    fill(&visited[0], &visited[v] + 1, false);
    for (int i = 0; i < e; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs();
    return 0;
}
