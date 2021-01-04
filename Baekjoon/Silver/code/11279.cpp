//
//  main.cpp
//  CodingTest
//
//  Created by sowon on 03/05/2020.
//  Copyright © 2020 sowon. All rights reserved.
//
#include <iostream>
#include <functional>
#include <queue>
using namespace std;

int main()
{
    int n, num, mx = 0;
    priority_queue<int, vector<int>, less<int>> pq;

    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &n);
        if (n == 0)
        {
            if (pq.size() <= 0)
            {
                printf("%d\n", 0);
            }
            else
            {
                mx = pq.top();
                pq.pop();
                printf("%d\n", mx);
            }
        }
        else if (n > 0)
        {
            pq.push(n);
        }
    }
    return 0;
}