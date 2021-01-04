#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, less<int>> mxq;
priority_queue<int, vector<int>, greater<int>> mnq;
int N, input, mid = 0;

void setMid(int data)
{
    if (mxq.empty() && mnq.empty())
    {
        mxq.push(data);
    }
    else if (mxq.size() > mnq.size())
    {
        if (mxq.top() > data)
        {
            mnq.push(mxq.top());
            mxq.pop();
            mxq.push(data);
        }
        else
        {
            mnq.push(data);
        }
    }
    else if (mxq.size() == mnq.size())
    {
        if (mnq.top() < data)
        {
            mxq.push(mnq.top());
            mnq.pop();
            mnq.push(data);
        }
        else
        {
            mxq.push(data);
        }
    }
    mid = mxq.top();
    cout << mid << "\n";
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> input;
        setMid(input);
    }
    return 0;
}