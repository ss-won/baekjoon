#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 41;
vector<pair<int, int>> memo(MAX, {-1, -1});

pair<int, int> fibozo(int n)
{
    if (memo[n].first != -1 && memo[n].second != -1)
        return memo[n];
    return memo[n] = {fibozo(n - 1).first + fibozo(n - 2).first, fibozo(n - 1).second + fibozo(n - 2).second};
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, zero, one;
    memo[0] = {1, 0};
    memo[1] = {0, 1};
    cin >> t;
    while (t--)
    {
        cin >> n;
        tie(zero, one) = fibozo(n);
        cout << zero << " " << one << "\n";
    }
    return 0;
}
