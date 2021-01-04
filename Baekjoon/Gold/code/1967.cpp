#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 10001;
int n, u, v, w;
int mx = 0, e;
bool visited[MAX];

void bfs(int s, vector<pair<int, int>> *adj)
{
    visited[s] = true;
    int cur, h;
    queue<pair<int, int>> q;
    q.push({s, 0});
    while (!q.empty())
    {
        tie(cur, h) = q.front();
        q.pop();
        for (int i = 0; i < (int)adj[cur].size(); i++)
        {
            tie(v, w) = adj[cur][i];
            if (!visited[v])
            {
                q.push({v, h + w});
                visited[v] = true;
                if (h + w > mx)
                {
                    mx = h + w;
                    e = v;
                }
            }
        }
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    vector<pair<int, int>> adj[n + 1];
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    fill(&visited[0], &visited[MAX - 1] + 1, false);
    bfs(1, adj);

    fill(&visited[0], &visited[MAX - 1] + 1, false);
    mx = 0;
    bfs(e, adj);
    cout << mx;
    return 0;
}
