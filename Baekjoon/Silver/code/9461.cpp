#include <iostream>
using namespace std;
const int MAX = 101;
long long cache[MAX];
int N, tc;

long long p(int n)
{
    if (n <= 3)
        return 1;
    if (n <= 5)
        return 2;
    if (cache[n] != -1)
        return cache[n];
    return cache[n] = p(n - 5) + p(n - 1);
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> tc;
    fill(&cache[0], &cache[MAX - 1] + 1, -1);
    while (tc--)
    {
        cin >> N;
        cout << p(N) << "\n";
    }
    return 0;
}
