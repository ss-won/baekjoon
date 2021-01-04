//
//  main.cpp
//  CodingTest
//
//  Created by sowon on 11/09/2020.
//  Copyright © 2020 sowon. All rights reserved.
//
#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <cmath>
using namespace std;
int N = 0;
string strcom[101][2];
bool visited[200];
string strarr[200];

void swap(int a)
{
    string tmp = strcom[a][0];
    strcom[a][0] = strcom[a][1];
    strcom[a][1] = tmp;
}

bool isValid(string target)
{
    for (int i = 2; i <= ceil((N - 1) / 2.0); i++)
    {
        if (strcom[i][0] != target.substr(0, i))
            swap(i);
        if (strcom[N - i][1] != target.substr(i))
            swap(N - i);
        if (strcom[i][0] + strcom[N - i][1] != target)
            return false;
    }
    return true;
}
void setStrcom()
{
    string target;
    int i = 0;
    for (; i < 4; i++)
    {
        if (i == 2)
            swap(N - 1);
        if (strcom[1][0] + strcom[N - 1][1] == strcom[N - 1][0] + strcom[1][1])
        {
            target = strcom[1][0] + strcom[N - 1][1];
            if (isValid(target))
                break;
        }
        if (i < 1 || i == 2)
            swap(1);
    }
    cout << target << "\n";
}

void print()
{
    for (int i = 0; i < 2 * N - 2; i++)
    {
        if (strcom[strarr[i].length()][0] == strarr[i] && !visited[strarr[i].length()])
        {
            cout << "P";
            visited[strarr[i].length()] = true;
        }
        else
            cout << "S";
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < 101; i++)
    {
        fill(&strcom[i][0], &strcom[i][1] + 1, "");
    }
    fill(&visited[0], &visited[N - 1] + 1, false);
    for (int i = 0; i < 2 * N - 2; i++)
    {
        cin >> strarr[i];
        if (strcom[strarr[i].length()][0] == "")
            strcom[strarr[i].length()][0] = strarr[i];
        else
            strcom[strarr[i].length()][1] = strarr[i];
    }
    setStrcom();
    print();
    return 0;
}