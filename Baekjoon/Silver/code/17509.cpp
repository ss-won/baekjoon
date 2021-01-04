#include <iostream>
#include <functional>
#include <queue>
using namespace std;

int main()
{
    int D = 0, V = 0, res = 0, sumV = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < 11; i++)
    {
        scanf("%d %d", &D, &V);
        pq.push(D);
        sumV += V;
    }

    for (int i = 11; i > 0; i--)
    {
        res += pq.top() * i;
        pq.pop();
    }
    res += sumV * 20;
    printf("%d", res);
    return 0;
}