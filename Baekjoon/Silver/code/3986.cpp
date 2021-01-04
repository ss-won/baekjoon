#include <iostream>
#include <algorithm>
#include <functional>
#include <deque>
#include <string>
using namespace std;
int n, res = 0;
string word;

bool ckgoodword(string s)
{
    deque<char> dq;
    for (int i = 0; i < (int)s.length(); i++)
    {
        if (dq.empty())
        {
            dq.push_back(s[i]);
        }
        else
        {
            if (dq.back() == s[i])
            {
                dq.pop_back();
            }
            else
            {
                dq.push_back(s[i]);
            }
        }
    }
    if (dq.empty())
        return true;
    else
        return false;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    while (n--)
    {
        cin >> word;
        if (ckgoodword(word))
            res++;
    }
    cout << res;
    return 0;
}
