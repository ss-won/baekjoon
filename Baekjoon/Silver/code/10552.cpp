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
#include <vector>
using namespace std;
int *pensioners;
bool *visited;
int res = 0;

bool solution(int P, bool state)
{
    if (pensioners[P] != 0)
    {
        if (visited[P])
        {
            return state = false;
        }
        visited[P] = true;
        res++;
        state = solution(pensioners[P], state);
    }
    return state;
}

int main()
{
    int N, M, P, a, b;
    cin >> N >> M >> P;
    visited = new bool[M + 1];
    pensioners = new int[M + 1];
    fill(&visited[0], &visited[M] + 1, false);
    fill(&pensioners[0], &pensioners[M] + 1, 0);

    for (int i = 0; i < N; i++)
    {
        cin >> a >> b;
        if (pensioners[b] == 0)
        {
            pensioners[b] = a;
        }
    }

    if (solution(P, true))
        cout << res;
    else
        cout << -1;
    return 0;
}