#include <iostream>
using namespace std;
const int MAX = 10001;
int p[MAX];
int cache[MAX];
int n;

int maxWineNum(int n)
{
    int &res = cache[n];
    if (n == 1)
        return res = p[n];
    if (n == 2)
        return res = p[n] + p[n - 1];
    if (n == 3)
        return res = max(max(p[n - 1], p[n - 2]) + p[n], maxWineNum(n - 1));
    if (res != -1)
        return res;
    return res = max(maxWineNum(n - 1), max(p[n - 1] + maxWineNum(n - 3), maxWineNum(n - 2)) + p[n]);
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }

    fill(&cache[0], &cache[MAX - 1] + 1, -1);

    cout << maxWineNum(n);
    return 0;
}
