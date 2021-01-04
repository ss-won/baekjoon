#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;
int n, m, res = 0;
pair<int, int> mv[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
char map[1000][1000];
int visited[1000][1000][2];
queue<tuple<int, int, bool, int>> q;

void bfs(pair<int, int> start, bool wall, int count)
{
    int x, y, w, c;
    tie(x, y) = start;
    if (x == n - 1 && y == m - 1)
    {
        cout << count << "\n";
        return;
    }
    visited[x][y][0] = count;
    q.push({x, y, wall, count});
    while (!q.empty())
    {
        tie(x, y, w, c) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + mv[i].first, ny = y + mv[i].second;
            if (nx == n - 1 && ny == m - 1)
            {
                res = c + 1;
                cout << res << "\n";
                return;
            }
            if (nx >= 0 && ny >= 0 && nx < n && ny < m)
            {
                if (w == 0 && (visited[nx][ny][0] == 0 || visited[nx][ny][0] > c + 1))
                {
                    if (map[nx][ny] == '0')
                    {
                        visited[nx][ny][0] = c + 1;
                        q.push({nx, ny, w, c + 1});
                    }
                    else
                    {
                        visited[nx][ny][1] = c + 1;
                        q.push({nx, ny, !w, c + 1});
                    }
                }
                else if (w == 1 && map[nx][ny] == '0' && (visited[nx][ny][1] == 0 || visited[nx][ny][1] > c + 1))
                {
                    visited[nx][ny][1] = c + 1;
                    q.push({nx, ny, w, c + 1});
                }
            }
        }
    }
    cout << -1 << "\n";
}

int main()
{
    //ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> map[i];
    }
    bfs({0, 0}, 0, 1);
    return 0;
}