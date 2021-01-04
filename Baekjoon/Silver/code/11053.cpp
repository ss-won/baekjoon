#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 1001;
int n;
int memo[MAX];

int getlis(int start, vector<int> arr)
{
    int mx = 1;
    if (memo[start] != 0)
        return memo[start];
    for (int i = start + 1; i < (int)arr.size(); i++)
    {
        if (arr[start] < arr[i])
        {
            mx = max(mx, getlis(i, arr) + 1);
        }
    }
    return memo[start] = mx;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int num, res = 0;
    vector<int> arr;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        arr.push_back(num);
    }
    for (int i = 0; i < (int)arr.size(); i++)
    {
        res = max(res, getlis(i, arr));
    }
    cout << res;
    return 0;
}
