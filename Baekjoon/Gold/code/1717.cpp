#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int n, m, a, b;
bool type;
int root[1000001];

int find(int v)
{
    if (root[v] != v)
        root[v] = find(root[v]);
    return root[v];
}

void Union(int u, int v)
{
    int rootu = find(u);
    int rootv = find(v);
    if (rootu != rootv)
    {
        root[rootv] = rootu;
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i <= n; i++)
    {
        root[i] = i;
    }
    while (m--)
    {
        cin >> type >> a >> b;
        if (type == 0)
        {
            if (find(a) != find(b))
            {
                Union(a, b);
            }
        }
        else
        {
            (find(a) == find(b)) ? cout << "YES\n" : cout << "NO\n";
        }
    }
    return 0;
}