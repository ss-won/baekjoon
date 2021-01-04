//
//  main.cpp
//  CodingTest
//
//  Created by sowon on 09/09/2020.
//  Copyright © 2020 sowon. All rights reserved.
//
#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
using namespace std;
int N = 0;
int res = 0;
vector<string> arr;
vector<bool> check;

bool compare(string a, string b)
{
    return a.length() > b.length();
}

void checking()
{
    for (int i = 0; i < (int)arr.size() - 1; i++)
    {
        for (int j = i + 1; j < (int)arr.size(); j++)
        {
            if (check[j])
                continue;
            if (arr[j] == arr[i].substr(0, arr[j].length()))
            {
                res++;
                check[j] = true;
            }
        }
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    arr.assign(N, "");
    check.assign(N, false);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end(), compare);
    checking();
    cout << N - res;
    return 0;
}