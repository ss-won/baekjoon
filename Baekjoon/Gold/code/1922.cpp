#include <iostream>
#include <functional>
#include <tuple>
#include <queue>
using namespace std;
int n, m, a, b, c, cost;
struct compare
{
    bool operator()(tuple<int, int, int> a, tuple<int, int, int> b)
    {
        return get<2>(a) > get<2>(b);
    }
};
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, compare> pq;
int root[1001];
int h[1001];

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
    if (h[rootu] > h[rootv])
    {
        root[rootv] = rootu;
    }
    else
    {
        if (h[rootu] == h[rootv])
        {
            h[rootv]++;
        }
        root[rootu] = rootv;
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
        h[i] = 1;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        pq.push({a, b, c});
    }
    while (!pq.empty())
    {
        tie(a, b, c) = pq.top();
        pq.pop();
        if (find(a) != find(b))
        {
            Union(a, b);
            cost += c;
        }
    }
    cout << cost;
    return 0;
}
