#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 100001;
int n, mx = 0, e;
vector<pair<int, int>> adj[MAX];
bool visited[MAX];

void dfs(int start, int h)
{
    int nv, nh;
    if (h > mx)
    {
        mx = h;
        e = start;
    }
    for (int i = 0; i < (int)adj[start].size(); i++)
    {
        tie(nv, nh) = adj[start][i];
        if (!visited[nv])
        {
            visited[nv] = true;
            dfs(nv, h + nh);
        }
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int v, input = 0, t = 0, u = 0, h;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> v;
        while (1)
        {
            cin >> input;
            if (input == -1)
                break;
            t++;
            if (t % 2 != 0)
            {
                u = input;
            }
            else
            {
                h = input;
                adj[v].push_back({u, h});
                adj[u].push_back({v, h});
            }
        }
    }

    fill(visited, visited + MAX, false);
    visited[1] = true;
    dfs(1, 0);

    fill(visited, visited + MAX, false);
    visited[e] = true;
    mx = 0;
    dfs(e, 0);

    cout << mx;
    return 0;
}
