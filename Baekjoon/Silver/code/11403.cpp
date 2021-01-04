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
int N = 0;               //정점의 개수
vector<vector<int>> adj; //인접행렬
bool visited[1000];
bool cango[1000][1000];

void dfs(int curr)
{
    //printf("visit %d\n",curr);
    for (int next : adj[curr])
    {
        if (!visited[next])
        {
            visited[next] = true;
            dfs(next);
        }
    }
}

int main()
{
    scanf("%d", &N);
    adj.resize(N);
    int tmp = 0;
    memset(cango, false, sizeof(cango));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &tmp);
            if (tmp)
            {
                adj[i].push_back(j);
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        dfs(i);
        for (int j = 0; j < N; j++)
        {
            if (visited[j])
            {
                cango[i][j] = true;
            }
            printf("%d ", cango[i][j]);
        }
        printf("\n");
        memset(visited, false, sizeof(visited));
    }

    return 0;
}