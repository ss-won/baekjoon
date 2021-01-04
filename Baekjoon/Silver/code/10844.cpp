#include <iostream>
using namespace std;
const int MAX = 101;
int cache[MAX][10];
int N, mod = 1000000000;

int setCache(int N, int i)
{
    if (N <= 0 || N > 100)
        return 0;
    int &res = cache[N][i];
    if (res != -1)
        return res;

    if (i == 0)
    {
        res = setCache(N - 1, i + 1);
        res %= mod;
    }
    else if (i == 9)
    {
        res = setCache(N - 1, i - 1);
        res %= mod;
    }
    else
    {
        res = setCache(N - 1, i - 1);
        res %= mod;
        res += setCache(N - 1, i + 1) % mod;
        res %= mod;
    }
    return res;
}

int getStairNum(int N)
{
    int res = 0;
    for (int i = 0; i < 10; i++)
    {
        res += setCache(N, i);
        res %= mod;
    }
    return res;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i <= N; i++)
    {
        if (i == 1)
        {
            fill(&cache[i][1], &cache[i][9] + 1, 1);
            cache[i][0] = 0;
        }
        else
        {
            fill(&cache[i][0], &cache[i][9] + 1, -1);
        }
    }
    cout << getStairNum(N);
    return 0;
}
