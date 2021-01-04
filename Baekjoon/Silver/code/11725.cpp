#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;
const int MAX = 1000001;
int n, u, v;
int parent[MAX];
vector<int> adj[MAX];
bool visited[MAX];

void setparent(int start)
{
    for (auto it : adj[start])
    {
        if (!visited[it])
        {
            parent[it] = start;
            visited[it] = true;
            setparent(it);
        }
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    visited[1] = true;
    setparent(1);
    for (int i = 2; i <= n; i++)
    {
        cout << parent[i] << "\n";
    }
    return 0;
}
