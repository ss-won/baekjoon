#include <iostream>
using namespace std;
const int MAX = 1001;
int rgb[MAX][3];
int cost[MAX][3];
int N;

int getMinCost(int n, int prev)
{
    int res = 9999999;
    if (n < 1)
        return 0;
    if (prev == 0 && cost[n][1] != 9999999 && cost[n][2] != 9999999)
    {
        return min(cost[n][1], cost[n][2]);
    }
    if (prev == 1 && cost[n][0] != 9999999 && cost[n][2] != 9999999)
    {
        return min(cost[n][0], cost[n][2]);
    }
    if (prev == 2 && cost[n][0] != 9999999 && cost[n][1] != 9999999)
    {
        return min(cost[n][0], cost[n][1]);
    }
    for (int i = 0; i < 3; i++)
    {
        if (i != prev)
        {
            cost[n][i] = getMinCost(n - 1, i) + rgb[n][i];
            res = min(cost[n][i], res);
        }
    }
    return res;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];
        fill(&cost[i][0], &cost[i][2] + 1, 9999999);
    }

    cout << getMinCost(N, -1);
    return 0;
}
