#include <iostream>
#include <algorithm>
#include <functional>
#include <tuple>
#include <queue>
#define MAX 1001
using namespace std;
int n, m, total = 0;
int map[MAX][MAX];
bool visited[MAX][MAX];
pair<int, int> mv[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
queue<tuple<int, int, int>> q;

void bfs()
{
    int x, y, d = 0;
    while (!q.empty())
    {
        tie(x, y, d) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + mv[i].first, ny = y + mv[i].second;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m)
            {
                if (map[nx][ny] == 0 && !visited[nx][ny])
                {
                    q.push({nx, ny, d + 1});
                    visited[nx][ny] = true;
                    total--;
                }
            }
        }
    }
    (total == 0) ? cout << d : cout << -1;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 1)
            {
                q.push({i, j, 0});
                visited[i][j] = true;
            }
            else if (map[i][j] == 0)
            {
                total++;
            }
        }
    }
    bfs();
    return 0;
}