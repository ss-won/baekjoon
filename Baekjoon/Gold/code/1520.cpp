#include <iostream>
#include <algorithm>
#include <functional>
#define MAX 500
using namespace std;
int m, n;
int map[MAX][MAX];
int memo[MAX][MAX];
bool visited[MAX][MAX];
pair<int, int> mv[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int getpaths(int x, int y)
{
    if (x < 0 || y < 0)
        return 0;
    if (x == m - 1 && y == n - 1)
    {
        return 1;
    }
    if (memo[x][y] != -1)
        return memo[x][y];
    memo[x][y] = 0;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + mv[i].first, ny = y + mv[i].second;
        if (nx >= 0 && nx < m && ny >= 0 && ny < n)
        {
            if (map[x][y] > map[nx][ny])
            {
                memo[x][y] += getpaths(nx, ny);
            }
        }
    }
    return memo[x][y];
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        fill(&memo[i][0], &memo[i][n - 1] + 1, -1);
        fill(&visited[i][0], &visited[i][n - 1] + 1, false);
    }
    cout << getpaths(0, 0);
}
