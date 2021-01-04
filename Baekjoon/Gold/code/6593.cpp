#include <iostream>
#include <algorithm>
#include <functional>
#include <tuple>
#include <queue>
using namespace std;
int l = -1, r = -1, c = -1;
bool visited[30][30][31];
char map[30][30][31];
tuple<int, int, int> mv[6] = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};
tuple<int, int, int> s;

void bfs()
{
    int z, x, y;
    tie(z, x, y) = s;
    visited[z][x][y] = true;
    queue<tuple<int, int, int, int>> q;
    q.push({z, x, y, 0});
    while (!q.empty())
    {
        int cz, cx, cy, ct;
        tie(cz, cx, cy, ct) = q.front();
        q.pop();
        for (int i = 0; i < 6; i++)
        {
            int nz = 0, nx = 0, ny = 0;
            tie(nz, nx, ny) = mv[i];
            nz += cz;
            nx += cx;
            ny += cy;
            if (nz >= 0 && nz < l && nx >= 0 && nx < r && ny >= 0 && ny < c)
            {
                if (map[nz][nx][ny] == 'E')
                {
                    cout << "Escaped in " << ct + 1 << " minute(s).\n";
                    return;
                }
                if (map[nz][nx][ny] != '#' && !visited[nz][nx][ny])
                {
                    q.push({nz, nx, ny, ct + 1});
                    visited[nz][nx][ny] = true;
                }
            }
        }
    }
    cout << "Trapped!\n";
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    while (1)
    {
        cin >> l >> r >> c;
        if (l == 0 && r == 0 && c == 0)
            break;
        for (int i = 0; i < l; i++)
        {
            for (int j = 0; j < r; j++)
            {
                fill(&visited[i][j][0], &visited[i][j][c] + 1, false);
            }
        }

        for (int i = 0; i < l; i++)
        {
            for (int j = 0; j < r; j++)
            {
                cin >> map[i][j];
                for (int k = 0; k < c; k++)
                {
                    if (map[i][j][k] == 'S')
                        s = {i, j, k};
                }
            }
        }
        bfs();
    }
}
