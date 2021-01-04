#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<double> stack;
int num[26];

double calculate(double n1, double n2, char op)
{
    if (op == '+')
        return n1 + n2;
    else if (op == '-')
        return n1 - n2;
    else if (op == '*')
        return n1 * n2;
    if (n2 == 0)
        return 0;
    return n1 / n2;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int N, input;
    double n1, n2;
    string exp;
    cin >> N >> exp;
    for (int i = 0; i < N; i++)
    {
        cin >> input;
        num[i] = input;
    }

    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] != '*' && exp[i] != '+' && exp[i] != '/' && exp[i] != '-')
        {
            stack.push_back(num[exp[i] - 'A']);
        }
        else
        {
            n2 = stack.back();
            stack.pop_back();
            n1 = stack.back();
            stack.pop_back();
            stack.push_back(calculate(n1, n2, exp[i]));
        }
    }
    cout.precision(2);
    cout << fixed << stack.back();
    return 0;
}
