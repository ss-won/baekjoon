#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
using namespace std;
int tc = 0;
int res = 0;

void solution(string str)
{
    int sum = 0;
    res = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '{')
            sum += 1;
        else
            sum -= 1;
        if (sum < 0)
        {
            res++;
            sum += 2;
            str[i] = '{';
        }
        else if (sum > 0 && str.length() - 1 - i < sum)
        {
            res++;
            sum -= 2;
            str[i] = '}';
        }
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    while (1)
    {
        cin >> str;
        if (str.find('-', 0) != -1)
            break;
        tc++;
        solution(str);
        cout << to_string(tc) << ". " << res << "\n";
    };
    return 0;
}