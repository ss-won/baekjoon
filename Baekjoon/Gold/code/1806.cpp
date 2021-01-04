//
//  main.cpp
//  CodingTest
//
//  Created by sowon on 05/09/2020.
//  Copyright © 2020 sowon. All rights reserved.
//
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int sequence[100000];

void minlength(int N, int S)
{
    int res = N + 1;
    int start = 0, end = 0, curr = sequence[0];
    while (end < N)
    {
        //printf("%d %d %d\n", start, end, curr);
        if (curr < S)
        {
            end++;
            curr += sequence[end];
        }
        else if (curr >= S)
        {
            res = min(res, end - start + 1);
            curr -= sequence[start];
            start++;
        }
        if (end == N - 1 && curr < S)
            break;
    }
    if (res == N + 1)
        res = 0;
    printf("%d", res);
}

int main()
{
    int N, S;
    scanf("%d %d", &N, &S);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &sequence[i]);
    }
    minlength(N, S);
    return 0;
}