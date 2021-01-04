#include <iostream>
using namespace std;
const int MAX = 301;
int N;
int stair[MAX];
int cache[MAX];
int getMax(int n)
{
    if (n > N || n < 0)
        return 0;
    int &ret = cache[n];
    if (ret != -1)
        return ret;
    return ret = max(getMax(n - 2), getMax(n - 3) + stair[n - 1]) + stair[n];
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    stair[0] = 0;
    for (int i = 1; i <= N; i++)
    {
        cin >> stair[i];
    }
    fill(&cache[0], &cache[MAX - 1] + 1, -1);
    cout << getMax(N);
    return 0;
}
