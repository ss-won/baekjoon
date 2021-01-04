// [트리의 지름 구하기 증명 참고] https: //blog.myungwoo.kr/112
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
#include <vector>
#define MAX 50001
using namespace std;
int N, T;
int max_p, min_w, root;
vector<pair<int, int>> adj[MAX];
bool visited[MAX];

void getpath(int curr, int len, int t)
{
    if (max_p < len)
    {
        max_p = len;
        min_w = t;
        root = curr;
    }
    else if (max_p == len)
    {
        if (min_w > t)
        {
            min_w = t;
            root = curr;
        }
    }
    for (int i = 0; i < adj[curr].size(); i++)
    {
        if (!visited[adj[curr][i].first])
        {
            visited[adj[curr][i].first] = true;
            getpath(adj[curr][i].first, len + 1, t + adj[curr][i].second);
        }
    }
}

void solution(int T)
{
    max_p = 1;
    min_w = 0;
    fill(&visited[0], &visited[N] + 1, false);
    visited[1] = true;
    max_p = 1;
    min_w = 0;
    getpath(1, 1, 0);

    fill(&visited[0], &visited[N] + 1, false);
    visited[root] = true;
    max_p = 1;
    min_w = 0;
    getpath(root, 1, 0);
    printf("%d", (min_w % T == 0) ? min_w / T : min_w / T + 1);
}

int main()
{
    int u, v, w;
    scanf("%d %d", &N, &T);
    for (int i = 0; i < N - 1; i++)
    {
        scanf("%d %d %d", &u, &v, &w);
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    solution(T);
    return 0;
}