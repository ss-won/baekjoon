//
//  main.cpp
//  CodingTest
//
//  Created by sowon on 02/05/2020.
//  Copyright © 2020 sowon. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int N, M, u, v = 0;
vector<vector<int>> adj;
bool visited[1000];
void dfs(int v)
{
    visited[v] = true;
    for (int next : adj[v])
    {
        if (!visited[next])
        {
            dfs(next);
        }
    }
}

int main()
{
    int components = 0;

    scanf("%d %d", &N, &M);
    adj.resize(N);
    memset(visited, false, sizeof(visited));

    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &u, &v);
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }

    for (int i = 0; i < N; i++)
    {
        sort(adj[i].begin(), adj[i].end());
    }

    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
        {
            dfs(i);
            components++;
        }
    }
    printf("%d\n", components);

    return 0;
}