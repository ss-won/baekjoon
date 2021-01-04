#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> stack;

void push(int num)
{
    stack.push_back(num);
}

int pop()
{
    if (stack.empty())
        return -1;
    int res = stack.back();
    stack.pop_back();
    return res;
}

int size()
{
    return (int)stack.size();
}

bool empty()
{
    return stack.empty();
}

int top()
{
    if (stack.empty())
        return -1;
    return stack.back();
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    string cmd;
    int N, num;
    cin >> N;
    while (N--)
    {
        cin >> cmd;
        if (cmd == "push")
        {
            cin >> num;
            push(num);
        }
        else if (cmd == "pop")
        {
            cout << pop() << "\n";
        }
        else if (cmd == "size")
        {
            cout << size() << "\n";
        }
        else if (cmd == "empty")
        {
            cout << empty() << "\n";
        }
        else
        {
            cout << top() << "\n";
        }
    }
    return 0;
}
