//
//  main.cpp
//  CodingTest
//
//  Created by sowon on 05/09/2020.
//  Copyright © 2020 sowon. All rights reserved.
//
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <functional>
using namespace std;
int *place;

void villain(int x, int y)
{
    for (int i = 2 * x; i < 2 * y - 1; i += 2)
    {
        if (place[i] == 1)
        {
            place[i] = 0;
        }
    }
}

void ckremains(int N)
{
    int walls = 0;
    for (int i = 1; i < 2 * N; i++)
    {
        if (place[i] == 1)
            walls += 2;
    }
    printf("%d", (walls + 2) / 2);
}

int main()
{
    int N, M, x, y;
    scanf("%d %d", &N, &M);
    place = (int *)malloc(sizeof(int) * 2 * N + 1);

    for (int i = 0; i < 2 * N + 1; i++)
    {
        if (i % 2 == 0)
        {
            place[i] = 1;
        }
        else
        {
            place[i] = 0;
        }
    }

    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &x, &y);
        villain(x, y);
    }

    ckremains(N);
    return 0;
}