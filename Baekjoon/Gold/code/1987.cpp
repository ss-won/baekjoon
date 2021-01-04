#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int r, c, res = 1;
bool visited[20][20];
bool alpha[26];
char map[20][20];
pair<int, int> mv[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(int x, int y, int l)
{
    if (l > res)
        res = l;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + mv[i].first, ny = y + mv[i].second;
        if (nx >= 0 && nx < r && ny >= 0 && ny < c)
        {
            if (!visited[nx][ny] && !alpha[map[nx][ny] - 'A'])
            {
                visited[nx][ny] = true;
                alpha[map[nx][ny] - 'A'] = true;
                dfs(nx, ny, l + 1);
                visited[nx][ny] = false;
                alpha[map[nx][ny] - 'A'] = false;
            }
        }
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        cin >> map[i];
    }
    visited[0][0] = true;
    alpha[map[0][0] - 'A'] = true;
    dfs(0, 0, 1);
    cout << res;
}
