#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
using namespace std;
bool state[1001];

int main()
{
    int N = 0, L = 0, pos = 0, count = 0;
    priority_queue<int, vector<int>, greater<int>> position;
    fill(&state[1], &state[1000], false);

    scanf("%d %d", &N, &L);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &pos);
        position.push(pos);
    }

    while (!position.empty())
    {
        pos = position.top();
        position.pop();
        if (!state[pos])
        {
            fill(&state[pos], &state[pos + L], true);
            count++;
        }
    }
    printf("%d", count);
    return 0;
}