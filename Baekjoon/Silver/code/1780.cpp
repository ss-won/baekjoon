//
//  main.cpp
//  CodingTest
//
//  Created by sowon on 04/09/2020.
//  Copyright © 2020 sowon. All rights reserved.
//
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int paper[2500][2500];

bool ckvalid(int N, int x, int y)
{
    if (N == 1)
        return true;
    for (int i = x; i < x + N; i++)
    {
        for (int j = y; j < y + N; j++)
        {
            if (paper[x][y] != paper[i][j])
                return false;
        }
    }
    return true;
}

void solution(int N, int x, int y, int result[])
{
    //printf("%d %d %d %d %d %d\n", N, x, y, result[0], result[1], result[2]);
    if (ckvalid(N, x, y))
    {
        if (paper[x][y] == -1)
        {
            result[0]++;
        }
        else if (paper[x][y] == 0)
        {
            result[1]++;
        }
        else
        {
            result[2]++;
        }
        return;
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            solution(N / 3, x + N / 3 * i, y + N / 3 * j, result);
        }
    }
    return;
}

int main()
{
    int N;
    int result[3] = {0, 0, 0};
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &paper[i][j]);
        }
    }
    solution(N, 0, 0, result);
    for (int i = 0; i < 3; i++)
    {
        printf("%d\n", result[i]);
    }
    return 0;
}