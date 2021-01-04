#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <map>
using namespace std;
int tc, f;
map<string, pair<string, int>> m;
string f1, f2;

string find(string v)
{
    if (v != m[v].first)
    {
        m[v] = {find(m[v].first), m[v].second};
    }
    return m[v].first;
}

int Union(string u, string v)
{
    string rootu = find(u);
    string rootv = find(v);
    if (rootu != rootv)
    {
        m[rootu] = {rootu, m[rootu].second + m[rootv].second};
        m[rootv] = {rootu, m[rootu].second};
    }
    return m[rootu].second;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> tc;
    while (tc--)
    {
        m.clear();
        cin >> f;
        for (int i = 0; i < f; i++)
        {
            cin >> f1 >> f2;
            if (m.find(f1) == m.end())
            {
                m[f1] = {f1, 1};
            }
            if (m.find(f2) == m.end())
            {
                m[f2] = {f2, 1};
            }
            cout << Union(f1, f2) << "\n";
        }
    }
    return 0;
}