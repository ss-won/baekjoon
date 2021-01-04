#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#define MAX 1000001
using namespace std;
int f, s, g, u, d, res = -1;
queue<pair<int, int>> q;
bool visited[MAX];

void bfs(int start)
{
    int curr, len;
    visited[start] = true;
    q.push({start, 0});
    while (!q.empty())
    {
        tie(curr, len) = q.front();
        q.pop();
        if (curr == g)
        {
            res = len;
            break;
        }
        if (curr + u <= f && !visited[curr + u])
        {
            visited[curr + u] = true;
            q.push({curr + u, len + 1});
        }
        if (curr - d >= 1 && !visited[curr - d])
        {
            visited[curr - d] = true;
            q.push({curr - d, len + 1});
        }
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> f >> s >> g >> u >> d;
    fill(&visited[0], &visited[f] + 1, false);
    bfs(s);
    (res != -1) ? cout << res : cout << "use the stairs";
}
