#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;
const int MAX = 500;
int w, h;
int height[MAX];

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> h >> w;
    for (int i = 0; i < w; i++)
    {
        cin >> height[i];
    }

    int f = 0, b = w - 1, res = 0;
    while (f != b)
    {
        int fh = height[f], bh = height[b];
        if (fh > bh)
        {
            while (b > 0 && bh > height[b - 1])
            {
                res += bh - height[b - 1];
                b--;
            }
            b--;
        }
        else
        {
            while (f < w - 1 && fh > height[f + 1])
            {
                res += fh - height[f + 1];
                f++;
            }
            f++;
        }
    }
    cout << res;
    return 0;
}
