#include <iostream>
using namespace std;
int n;
int memo[1001];

int dp(int n)
{
    if (memo[n] != -1)
        return memo[n];
    return memo[n] = (dp(n - 1) + dp(n - 2)) % 10007;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    fill(&memo[0], &memo[1000] + 1, -1);
    memo[1] = 1;
    memo[2] = 2;
    cin >> n;
    cout << dp(n);
    return 0;
}
