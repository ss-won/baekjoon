#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
using namespace std;

int main()
{
    int N = 0;
    queue<int> card;

    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        card.push(i);
    }

    while (card.size() > 1)
    {
        card.pop();
        card.push(card.front());
        card.pop();
    }
    printf("%d", card.front());
    return 0;
}
