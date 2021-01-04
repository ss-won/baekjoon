#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;
const int MAX = 91;
long long memo[MAX];

long long fibo(int n)
{
    if (n == 0 || n == 1)
        return n;
    if (memo[n] != -1)
        return memo[n];
    return memo[n] = fibo(n - 1) + fibo(n - 2);
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    fill(&memo[0], &memo[MAX], -1);
    memo[0] = 0;
    memo[1] = 1;
    cout << fibo(n);
    return 0;
}
