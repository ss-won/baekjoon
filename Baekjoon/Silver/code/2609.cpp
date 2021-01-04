#include <iostream>
#include <algorithm>

using namespace std;

void GCommonFac(int a, int b)
{
    int res = 0;
    for (int i = 1; i <= max(a, b); i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            if (i >= res)
            {
                res = i;
            }
        }
    }
    cout << res << endl;
}

void LCommonMul(int a, int b)
{
    int res = max(a, b);
    for (int i = 1; i <= min(a, b); i++)
    {
        if (res % min(a, b) == 0)
        {
            break;
        }
        res += max(a, b);
    }
    cout << res << endl;
}

int main()
{
    int a, b = 0;
    cin >> a >> b;
    GCommonFac(a, b);
    LCommonMul(a, b);
    return 0;
}
