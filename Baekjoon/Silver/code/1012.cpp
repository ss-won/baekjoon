//
//  main.cpp
//  CodingTest
//
//  Created by sowon on 01/05/2020.
//  Copyright © 2020 sowon. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
int m, n = 0;                                     //m:행,n:열
int v = 0;                                        //vertex 개수10
int s[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; //상,우,하,좌
bool visited[51][51];
int bat[51][51];
void dfs(int v, int u)
{
    visited[v][u] = true;
    for (int i = 0; i < 4; i++)
    {
        int nv = v + s[i][0];
        int nu = u + s[i][1];
        if (nv >= 0 && nu >= 0)
        {
            if (!visited[nv][nu] && bat[nv][nu] == 1)
            {
                dfs(nv, nu);
            }
        }
    }
}

int main()
{
    int tc = 0;
    cin >> tc;

    while (tc--)
    {

        int x, y = 0;       //x:x좌표 y:y좌표
        int components = 0; //컴포넌트갯수
        vector<pair<int, int>> V;
        memset(visited, false, sizeof(visited));
        memset(bat, 0, sizeof(bat));

        cin >> m >> n >> v;

        //vertex 할당
        for (int j = 0; j < v; j++)
        {
            cin >> x >> y;
            V.push_back(make_pair(x, y));
            bat[x][y] = 1;
        }

        sort(V.begin(), V.end());

        //dfs돌기
        for (int j = 0; j < v; j++)
        {
            x = V[j].first;
            y = V[j].second;
            if (!visited[x][y])
            {
                dfs(x, y);
                components++;
            }
        }
        //출력
        cout << components << endl;
    }
    return 0;
}