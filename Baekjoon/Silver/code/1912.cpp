#include <iostream>
using namespace std;
const int MAX = 100001;
int cache[2][MAX];
int seq[MAX];
int n;

int maxContinueSum(int n, int sp)
{
    if (n < 0 || n >= MAX)
        return 0;
    if (cache[sp][n] != -1001)
        return cache[sp][n];
    if (n == 1)
        return seq[1];
    if (n == 2)
    {
        if (sp == 0)
            return cache[0][2] = seq[1];
        else
            return cache[1][2] = max(seq[2] + seq[1], seq[2]);
    }
    if (sp == 0)
        return cache[0][n] = max(maxContinueSum(n - 1, 0), maxContinueSum(n - 1, 1));
    return cache[1][n] = max(maxContinueSum(n - 1, 1) + seq[n], seq[n]);
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> seq[i];
    }
    for (int i = 0; i < 2; i++)
    {
        fill(&cache[i][0], &cache[i][MAX - 1] + 1, -1001);
    }

    cout << max(maxContinueSum(n, 0), maxContinueSum(n, 1));
    return 0;
}
