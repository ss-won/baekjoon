#include <iostream>
using namespace std;

int main()
{
    int L = 0, P = 0, V = 0, index = 0, result = 0;
    while (1)
    {
        result = 0;
        index++;
        scanf("%d %d %d", &L, &P, &V);

        if (L == 0 && P == 0 && V == 0)
            break;
        result += (V / P) * L;
        if (V % P < L)
        {
            result += V % P;
        }
        else
        {
            result += L;
        }
        printf("Case %d: %d\n", index, result);
    }
    return 0;
}
