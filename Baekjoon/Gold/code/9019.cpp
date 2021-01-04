#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <queue>
#define MAX 10000
using namespace std;
int t, s, e;
int memo[MAX][4];
bool visited[MAX];

void dslr(int curr)
{
    memo[curr][0] = curr * 2 % 10000;
    memo[curr][1] = (curr == 0) ? 9999 : curr - 1;
    memo[curr][2] = (curr * 10) % 10000 + (curr / 1000);
    memo[curr][3] = (curr / 10) + (curr % 10 * 1000);
}

void bfs()
{
    queue<pair<int, string>> q;
    visited[s] = true;
    q.push({s, ""});
    while (!q.empty())
    {
        int curr;
        string depth;
        tie(curr, depth) = q.front();
        q.pop();
        int d = memo[curr][0], s = memo[curr][1], l = memo[curr][2], r = memo[curr][3];
        if (d == 0 && s == 0 && l == 0 && r == 0)
        {
            dslr(curr);
            d = memo[curr][0];
            s = memo[curr][1];
            l = memo[curr][2];
            r = memo[curr][3];
        }
        if (!visited[d])
        {
            if (d == e)
            {
                cout << depth + 'D' << "\n";
            }
            q.push({d, depth + 'D'});
            visited[d] = true;
        }
        if (!visited[s])
        {
            if (s == e)
            {
                cout << depth + 'S' << "\n";
            }
            q.push({s, depth + 'S'});
            visited[s] = true;
        }
        if (!visited[l])
        {
            if (l == e)
            {
                cout << depth + 'L' << "\n";
            }
            q.push({l, depth + 'L'});
            visited[l] = true;
        }
        if (!visited[r])
        {
            if (r == e)
            {
                cout << depth + 'R' << "\n";
            }
            q.push({r, depth + 'R'});
            visited[r] = true;
        }
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--)
    {
        cin >> s >> e;
        fill(visited, visited + MAX, false);
        bfs();
    }
}