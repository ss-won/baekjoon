#include <iostream>
#include <vector>
using namespace std;
const int MAX = 501;
vector<long long> triangle[MAX];
long long cache[MAX][MAX];

long long getMax(int x, int y, int n)
{
    if (y > x || y >= n || x >= n || y < 0 || x < 0)
        return 0;
    if (n - 1 == x)
        return triangle[x][y];
    if (cache[x][y] != -1)
        return cache[x][y];
    return cache[x][y] = max(getMax(x + 1, y, n), getMax(x + 1, y + 1, n)) + triangle[x][y];
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    long long num;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        fill(&cache[i][0], &cache[i][MAX - 1] + 1, -1);
        for (int j = 0; j <= i; j++)
        {
            cin >> num;
            triangle[i].push_back(num);
        }
    }
    cout << getMax(0, 0, n);
    return 0;
}
