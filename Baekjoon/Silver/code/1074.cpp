#include <iostream>
#include <cmath>
using namespace std;
int N, r, c, res = 0;
bool answer = false;
pair<int, int> mv[4] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};

void movez(int size, int sx, int sy)
{
    if (size == 2)
    {
        for (int i = 0; i < 4; i++)
        {
            int cx = sx + mv[i].first, cy = sy + mv[i].second;
            if (cx == r && cy == c)
            {
                cout << res;
                answer = true;
                return;
            }
            res++;
        }
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            if (answer)
                break;
            int nexts = size / 2, nx = sx + mv[i].first * nexts, ny = sy + mv[i].second * nexts;
            if (r >= nx && r < nx + nexts && c >= ny && c < ny + nexts)
                movez(nexts, nx, ny);
            else
                res += nexts * nexts;
        }
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> r >> c;
    //cout << (int)pow(2.0,N);
    movez((int)pow(2.0, N), 0, 0);
    return 0;
}