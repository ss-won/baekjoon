#include <iostream>
#include <vector>
using namespace std;
vector<int> stack;
vector<char> exp;
int nxt = 1;

// simulation
bool ckstack(int cur)
{
    if (!stack.empty() && stack.back() > cur)
        return false;

    if (stack.empty() || stack.back() < cur)
    {
        while (nxt <= cur)
        {
            stack.push_back(nxt);
            exp.push_back('+');
            nxt++;
        }
    }

    if (stack.back() == cur)
    {
        stack.pop_back();
        exp.push_back('-');
    }

    return true;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int n, cur;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> cur;
        if (!ckstack(cur))
        {
            cout << "NO";
            return 0;
        }
    }

    for (auto e : exp)
    {
        cout << e << "\n";
    }

    return 0;
}
