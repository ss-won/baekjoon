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
#include <cstring>
using namespace std;
deque<int> names[21];
int N, K;
long long res = 0;

void solution()
{
    int top = 0, n = 0, s = 0;
    for (int i = 2; i < 21; i++)
    {
        if (names[i].empty() || names[i].size() == 1)
            continue;
        while (names[i].size() > 1)
        {
            top = names[i].front();
            names[i].pop_front();
            for (deque<int>::iterator it = names[i].begin() + s; it < names[i].end(); it++)
            {
                if (*it <= top + K)
                    n++;
                else
                    break;
            }
            res += n;
            s = n - 1;
            n--;
        }
    }
    cout << res << "\n";
}

int main()
{
    string name;
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> name;
        names[name.length()].push_back(i);
    }
    solution();
    return 0;
}