#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
using namespace std;
int N = 0;
vector<string> map;
bool visited[101][101];
pair<int, int> mv[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
queue<pair<int, int>> start;
queue<pair<int, int>> q;

void check_child(pair<int, int> child, char target, bool origin)
{
    int x, y;
    tie(x, y) = child;
    if (origin && !visited[x][y] && map[x][y] == target)
    {
        q.push({x, y});
        visited[x][y] = true;
    }
    else if (origin && !visited[x][y])
    {
        start.push({x, y});
    }
    else if (!origin && !visited[x][y])
    {
        if (target == 'B' && map[x][y] == target)
        {
            q.push({x, y});
            visited[x][y] = true;
        }
        else if ((target == 'R' || target == 'G') && map[x][y] != 'B')
        {
            q.push({x, y});
            visited[x][y] = true;
        }
        else
            start.push({x, y});
    }
}

void push_child(pair<int, int> curr, char target, bool origin)
{
    int x, y;
    tie(x, y) = curr;
    for (int i = 0; i < 4; i++)
    {
        if (x + mv[i].first < N && x + mv[i].first >= 0 && y + mv[i].second < N && y + mv[i].second >= 0)
        {
            check_child({x + mv[i].first, y + mv[i].second}, target, origin);
        }
    }
}

void bfs(pair<int, int> start, bool origin = true)
{
    int x, y;
    tie(x, y) = start;
    visited[x][y] = true;
    char target = map[x][y];
    q.push({x, y});
    while (!q.empty())
    {
        tie(x, y) = q.front();
        q.pop();
        push_child({x, y}, target, origin);
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    string input;
    int res_origin = 0, res = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        fill(&visited[i][0], &visited[i][100] + 1, false);
    }

    for (int i = 0; i < N; i++)
    {
        cin >> input;
        map.push_back(input);
    }

    start.push({0, 0});
    while (!start.empty())
    {
        int x, y;
        tie(x, y) = start.front();
        start.pop();
        if (visited[x][y])
            continue;
        bfs({x, y});
        res_origin++;
    }

    for (int i = 0; i < N; i++)
    {
        fill(&visited[i][0], &visited[i][100] + 1, false);
    }
    start.push({0, 0});
    while (!start.empty())
    {
        int x, y;
        tie(x, y) = start.front();
        start.pop();
        if (visited[x][y])
            continue;
        bfs({x, y}, false);
        res++;
    }
    cout << res_origin << " " << res << "\n";
    return 0;
}