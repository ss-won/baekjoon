#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;
int n, m, input;
int root[201];

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
    for (int i = 1; i <= n; i++)
    {
        root[i] = i;
    }
    for (int x = 1; x <= n; x++)
    {
        for (int y = 1; y <= n; y++)
        {
            cin >> input;
            if (input == 1)
            {
                if (find(x) != find(y))
                {
                    Union(x, y);
                }
            }
        }
    }
    int curr = 0;
    for (int i = 0; i < m; i++)
    {
        if (curr == 0)
        {
            cin >> curr;
            continue;
        }
        cin >> input;
        if (input == 0 || find(input) != find(curr))
        {
            cout << "NO";
            return 0;
        }
        curr = input;
    }
    cout << "YES";
    return 0;
}