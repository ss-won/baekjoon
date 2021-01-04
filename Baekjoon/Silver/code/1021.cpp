#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
using namespace std;
deque<int> q;
int sum = 0;
void solution(int p)
{
    int gap_f = 0;
    int gap_b = 0;
    for (deque<int>::iterator it = q.begin(); it < q.end(); it++)
    {
        gap_f++;
        if (*it == p)
        {
            gap_f -= 1;
            gap_b = (int)q.size() - gap_f;
            break;
        }
    }
    sum += (gap_f < gap_b) ? gap_f : gap_b;
    if (gap_f == 0)
    {
        q.pop_front();
    }
    else if (gap_f >= gap_b)
    {
        while (gap_f--)
        {
            q.push_back(q.front());
            q.pop_front();
        }
        q.pop_front();
    }
    else if (gap_f < gap_b)
    {
        while (gap_b--)
        {
            q.push_front(q.back());
            q.pop_back();
        }
        q.pop_front();
    }
}
int main()
{
    int N, M, pos;
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++)
    {
        q.push_back(i);
    }
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &pos);
        solution(pos);
    }
    printf("%d", sum);
    return 0;
}
