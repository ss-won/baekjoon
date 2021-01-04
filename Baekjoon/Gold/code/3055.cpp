#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <tuple>
using namespace std;
int r, c, t = 1;
char map[51][51];
bool visited[51][51];
pair<int, int> mv[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
pair<int, int> s;
queue<pair<int, int>> water;
queue<tuple<int, int, int>> q;

void watermv()
{
    // 돌, 비버의 좌표 뺴고는 이동이 가능하다.
    if (water.empty())
        return;
    int s = (int)water.size(), wx, wy;
    while (s--)
    {
        tie(wx, wy) = water.front();
        water.pop();
        for (int j = 0; j < 4; j++)
        {
            int nx = wx + mv[j].first, ny = wy + mv[j].second;
            if (nx >= 0 && nx < r && ny >= 0 && ny < c)
            {
                if (map[nx][ny] != 'X' && map[nx][ny] != 'D' && map[nx][ny] != '*')
                {
                    map[nx][ny] = '*';
                    water.push({nx, ny});
                }
            }
        }
    }
}

void bfs()
{
    int sx, sy, cx, cy, lt = -1, ct;
    bool ans = false;
    tie(sx, sy) = s;
    visited[sx][sy] = true;
    q.push({sx, sy, 0});
    while (!q.empty())
    {
        tie(cx, cy, ct) = q.front();
        q.pop();
        if (map[cx][cy] == 'D')
        {
            ans = true;
            t = ct;
            break;
        }
        if (ct > lt)
        {
            watermv();
            lt = ct;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = cx + mv[i].first, ny = cy + mv[i].second;
            if (nx >= 0 && nx < r && ny >= 0 && ny < c)
            {
                // 이미 이전에 방문한 곳, 물이 있는곳, 돌이 있는 곳은 이동하지 않는다.
                if (!visited[nx][ny] && map[nx][ny] != '*' && map[nx][ny] != 'X')
                {
                    q.push({nx, ny, ct + 1});
                    visited[nx][ny] = true;
                }
            }
        }
    }
    if (!ans)
        cout << "KAKTUS";
    else
        cout << t;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        cin >> map[i];
        for (int j = 0; j < c; j++)
        {
            if (map[i][j] == 'S')
            {
                s = {i, j};
            }
            else if (map[i][j] == '*')
            {
                water.push({i, j});
            }
        }
    }
    bfs();
    return 0;
}
