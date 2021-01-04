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
int memo[1000001];

int minCal(int N)
{
    if (N == 1)
        return memo[1];
    if (memo[N] != -1)
        return memo[N];

    int res = 1000000, tmp = 0;
    if (N % 3 == 0)
    {
        tmp = minCal(N / 3) + 1;
        if (res > tmp)
            res = tmp;
    }
    if (N % 2 == 0)
    {
        tmp = minCal(N / 2) + 1;
        if (res > tmp)
            res = tmp;
    }
    tmp = minCal(N - 1) + 1;
    if (res > tmp)
        res = tmp;
    //printf("%d, %d\n", N, res);
    return memo[N] = res;
}

int main()
{
    int N;
    fill(&memo[0], &memo[1000000] + 1, -1);
    memo[1] = 0;
    scanf("%d", &N);
    printf("%d", minCal(N));
    return 0;
}