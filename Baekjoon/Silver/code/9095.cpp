//
//  main.cpp
//  CodingTest
//
//  Created by sowon on 03/05/2020.
//  Copyright © 2020 sowon. All rights reserved.
//
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int memo[12];

int sumCom(int N)
{
    //printf("%d\n", N);
    if (N <= 0)
        return memo[0];
    if (memo[N] != 0)
        return memo[N];
    return memo[N] = sumCom(N - 1) + sumCom(N - 2) + sumCom(N - 3);
}

int main()
{
    int T, N;
    fill(&memo[0], &memo[11] + 1, 0);
    memo[1] = 1;
    memo[2] = 2;
    memo[3] = 4;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        scanf("%d", &N);
        printf("%d\n", sumCom(N));
    }
    return 0;
}