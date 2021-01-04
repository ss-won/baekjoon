#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;
int sdoku[10][10];
vector<pair<int, int>> zero;
int bound[3] = {3, 6, 9};
bool finished = false;

bool checking(int id)
{
    bool ck[10];
    fill(ck, ck + 10, false);
    int cx, cy;
    tie(cx, cy) = zero[id];
    /* 3*3 칸 checking */
    auto bx = upper_bound(bound, bound + 3, cx) - bound;
    auto by = upper_bound(bound, bound + 3, cy) - bound;
    for (int i = bound[bx] - 1; i >= bound[bx] - 3; i--)
    {
        for (int j = bound[by] - 1; j >= bound[by] - 3; j--)
        {
            if (sdoku[i][j] == 0)
                continue;
            if (!ck[sdoku[i][j]])
                ck[sdoku[i][j]] = true;
            else
            {
                return false;
            }
        }
    }
    /* 세로축 checking */
    fill(ck, ck + 10, false);
    for (int i = 0; i < 9; i++)
    {
        if (sdoku[i][cy] == 0)
            continue;
        if (!ck[sdoku[i][cy]])
            ck[sdoku[i][cy]] = true;
        else
        {
            return false;
        }
    }
    /* 가로축 checking */
    fill(ck, ck + 10, false);
    for (int j = 0; j < 9; j++)
    {
        if (sdoku[cx][j] == 0)
            continue;
        if (!ck[sdoku[cx][j]])
            ck[sdoku[cx][j]] = true;
        else
        {
            return false;
        }
    }
    return true;
}

void fill(int id)
{
    if (id == (int)zero.size())
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << sdoku[i][j] << " ";
            }
            cout << "\n";
        }
        finished = true;
        return;
    }

    for (int i = 1; i <= 9; i++)
    {
        sdoku[zero[id].first][zero[id].second] = i;
        if (checking(id))
        {
            fill(id + 1);
        }
        sdoku[zero[id].first][zero[id].second] = 0;
        if (finished)
            break;
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> sdoku[i][j];
            if (sdoku[i][j] == 0)
                zero.push_back({i, j});
        }
    }
    fill(0);
    return 0;
}
