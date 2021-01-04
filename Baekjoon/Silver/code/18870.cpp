#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
using namespace std;
int N, input;
struct compare
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.first > b.first;
    }
};

priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    vector<int> matrix(N, 0);

    for (int i = 0; i < N; i++)
    {
        cin >> input;
        pq.push({input, i});
    }

    int k = 0, v, i, prev = pq.top().first;
    while (!pq.empty())
    {
        tie(v, i) = pq.top();
        if (prev == v)
        {
            matrix[i] = k;
        }
        else
        {
            matrix[i] = ++k;
            prev = v;
        }
        pq.pop();
    }

    for (int i = 0; i < N; i++)
    {
        cout << matrix[i] << " ";
    }
    return 0;
}
