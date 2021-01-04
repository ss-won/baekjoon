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
#include <queue>
#include <tuple>
using namespace std;
bool compare(tuple<int, int> a, tuple<int, int> b)
{
    if (get<1>(a) == get<1>(b))
    {
        return get<0>(a) < get<0>(b);
    }
    return get<1>(a) < get<1>(b);
};

int main()
{
    int N = 0;
    int start = 0, end = 0, prev = 0, res = 0;
    vector<tuple<int, int>> conferences;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &start, &end);
        conferences.push_back(make_tuple(start, end));
    }

    sort(conferences.begin(), conferences.end(), compare);

    for (int i = 0; i < conferences.size(); i++)
    {
        tie(start, end) = conferences[i];
        if (prev <= start)
        {
            res++;
            prev = end;
        }
    }
    printf("%d", res);
    return 0;
}