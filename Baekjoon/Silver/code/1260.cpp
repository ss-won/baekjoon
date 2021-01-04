#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
vector<int> a[1001];
bool check[1001];

void dfs(int node)
{
    check[node] = true;
    cout << node << " ";
    for (int i = 0; i < a[node].size(); i++)
    {
        int next = a[node][i];
        if (!check[next])
        {
            dfs(next);
        }
    }
}
void bfs(int start)
{
    queue<int> q;
    memset(check, false, sizeof(check));
    q.push(start);
    while (!q.empty())
    {
        int node = q.front();
        check[node] = true;
        q.pop();
        cout << node << " ";
        for (int i = 0; i < a[node].size(); i++)
        {
            int next = a[node][i];
            if (!check[next])
            {
                check[next] = true;
                q.push(next);
            }
        }
    }
}

int main()
{
    int n, m, s;
    cin >> n >> m >> s;
    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    memset(check, false, sizeof(check));
    for (int i = 1; i <= n; i++)
    {
        sort(a[i].begin(), a[i].end());
    }
    dfs(s);
    cout << endl;
    bfs(s);
    return 0;
}