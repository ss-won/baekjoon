#include <iostream>
#include <algorithm>
#include <functional>
#include <cstring>
#include <vector>
#include <queue>
#define MAX 25
using namespace std;
int n, group = 0, h = 0;
char map[MAX][MAX];
bool visited[MAX][MAX];
pair<int, int> mv[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
queue<pair<int, int>> q;
priority_queue<int, vector<int>, greater<int>> hq;

void bfs(int x, int y)
{
    q.push({x, y});
    visited[x][y] = true;
    h++;
    while (!q.empty())
    {
        tie(x, y) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + mv[i].first, ny = y + mv[i].second;
            if (nx >= 0 && nx < n && ny >= 0 && ny < n)
            {
                if (map[nx][ny] == '1' && !visited[nx][ny])
                {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                    h++;
                }
            }
        }
    }
    hq.push(h);
    h = 0;
}

int main()
{
    //ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> map[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] == '0')
                continue;
            if (map[i][j] == '1' && !visited[i][j])
            {
                bfs(i, j);
                group++;
            }
        }
    }
    cout << group << "\n";
    while (!hq.empty())
    {
        cout << hq.top() << "\n";
        hq.pop();
    }
    return 0;
}