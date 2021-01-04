#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
using namespace std;
int n, mx = -2147483648;
string exp;
int idx[21] = {
    0,
};

int operators(int left, int right, char op)
{
    int res = 0;
    if (op == '+')
    {
        res = left + right;
    }
    else if (op == '-')
    {
        res = left - right;
    }
    else
    {
        res = left * right;
    }
    return res;
}

int total(string exp)
{
    char op;
    int left = (exp[0] != 'c') ? exp[0] - '0' : idx[0], right;
    for (int i = 2; i <= (int)exp.length() - 1; i += 2)
    {
        right = (exp[i] != 'c') ? exp[i] - '0' : idx[i];
        op = exp[i - 1];
        left = operators(left, right, op);
    }
    return left;
}

void setCase(int cn, int cur, int top, string exp)
{
    if (cn == cur)
    {
        mx = max(total(exp), mx);
        return;
    }

    string next;
    for (int i = top; i < (int)exp.length(); i += 2)
    {
        idx[i - 2] = operators(exp[i - 2] - '0', exp[i] - '0', exp[i - 1]);
        next = exp.substr(0, i - 2) + "c" + exp.substr(i + 1);
        setCase(cn, cur + 1, i + 2, next);
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    cin >> exp;
    if (n == 1)
    {
        cout << exp[0] - '0';
        return 0;
    }
    if (n == 3)
    {
        cout << operators(exp[0] - '0', exp[2] - '0', exp[1]);
        return 0;
    }

    for (int i = 1; i <= (n + 1) / 4; i++)
    {
        setCase(i, 0, 2, exp);
    }
    cout << mx;
    return 0;
}
