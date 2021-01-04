#include <iostream>
#include <vector>
using namespace std;
const int MAX = 500001;
vector<int> plat[MAX];

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int n, p, ln, pn, res = 0;
    cin >> n >> p;

    for (int i = 0; i < n; i++)
    {
        cin >> ln >> pn;
        if (plat[ln].empty() || plat[ln].back() < pn)
        {
            plat[ln].push_back(pn);
            res++;
        }
        else if (plat[ln].back() > pn)
        {
            while (1)
            {
                plat[ln].pop_back();
                res++;
                if (plat[ln].empty() || plat[ln].back() <= pn)
                {
                    if (plat[ln].empty() || plat[ln].back() < pn)
                    {
                        plat[ln].push_back(pn);
                        res++;
                    }
                    break;
                }
            }
        }
    }
    cout << res;
    return 0;
}
