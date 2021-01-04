//
//  main.cpp
//  CodingTest
//
//  Created by sowon on 06/09/2020.
//  Copyright © 2020 sowon. All rights reserved.
//
#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
using namespace std;
deque<int> q;
priority_queue<int, vector<int>, less<int>> mx;
int res = 0;

void solution(int M)
{
    if (q.size() == 1)
    {
        res = 1;
        return;
    }

    int m = M;
    //deque<int>::iterator it = q.begin();
    while (!q.empty())
    {
        int top = q.front();
        //printf("%d %d %d %d\n", top, mx.top(), res, m);
        if (mx.top() > top)
        {
            m = (m == 0) ? (int)q.size() - 1 : m -= 1;
            q.push_back(top);
            q.pop_front();
        }
        else
        {
            res++;
            q.pop_front();
            mx.pop();
            if (m == 0)
                return;
            m = (m == 0) ? (int)q.size() - 1 : m -= 1;
        }
    }
}

int main()
{
    int tc, N, M, input;
    scanf("%d", &tc);
    for (int i = 0; i < tc; i++)
    {
        scanf("%d %d", &N, &M);
        while (!mx.empty())
        {
            mx.pop();
        }
        q.clear();
        res = 0;
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &input);
            q.push_back(input);
            mx.push(input);
        }
        solution(M);
        printf("%d\n", res);
    }
    return 0;
}