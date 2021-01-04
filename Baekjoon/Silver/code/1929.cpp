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
#include <cmath>
using namespace std;
bool prime[1000001];
int main()
{
    int M, N;
    fill(&prime[0], &prime[1000000] + 1, true);
    // **1은 소수가 아니다.
    prime[0] = false;
    prime[1] = false;
    scanf("%d %d", &M, &N);

    for (int i = 2; i <= sqrt(N); i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= N; j += i)
            {
                prime[j] = false;
            }
        }
    }

    for (int i = M; i <= N; i++)
    {
        if (prime[i])
        {
            printf("%d\n", i);
        }
    }
    return 0;
}