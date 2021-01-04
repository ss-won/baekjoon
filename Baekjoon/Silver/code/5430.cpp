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
#include <cstdlib>
#define MAX 400001
using namespace std;
deque<int> q;
bool state = true;
bool rev = false;
int tc = 0;

void D()
{
    if (q.size() == 0)
    {
        state = false;
    }
    else
    {
        if (!rev)
            q.pop_front();
        else
            q.pop_back();
    }
}

void print()
{
    string res = "[";
    if (!state)
    {
        cout << "error\n";
    }
    else
    {
        while (!q.empty())
        {
            if (!rev)
            {
                res += to_string(q.front()) + ",";
                q.pop_front();
            }
            else
            {
                res += to_string(q.back()) + ",";
                q.pop_back();
            }
        }
        if (res[res.length() - 1] == ',')
            res[res.length() - 1] = ']';
        else
            res += "]";
        cout << res << "\n";
    }
}

int main()
{
    int n;
    string ac, input;
    char arr[MAX];
    char *token;
    cin >> tc;
    while (tc--)
    {
        state = true;
        rev = false;
        ac.clear();
        n = 0;
        cin >> ac >> n >> arr;

        token = strtok(arr, "[,]");
        while (token != NULL)
        {
            q.push_back(atoi(token));
            token = strtok(NULL, "[,]");
        }

        for (int i = 0; i < ac.length(); i++)
        {
            if (ac[i] == 'R')
            {
                rev = !rev;
            }
            else if (ac[i] == 'D')
            {
                D();
            }
            if (!state)
                break;
        }
        print();
    }
    return 0;
}