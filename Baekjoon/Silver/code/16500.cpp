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
#include <vector>
#include <string>
using namespace std;
int memo[100];

bool ckstring(int idx, string S, vector<string> A){
    if(idx == S.length()) return true;
    if(memo[idx] != -1)
        return memo[idx];
    int res = memo[idx];
    res = 0;
    for(int i=0;i<A.size();i++){
        int len = A[i].length();
        if(S.length() - idx + 1 < len) continue;
        if(S.substr(idx, len) == A[i]){
            res = ckstring(idx+len, S, A);
        }
        if(res) break;
    }
    return memo[idx] = res;
};

int main() {
    int N = 0;
    string S, input;
    vector<string> a;
    fill(&memo[0], &memo[99], -1);
    cin >> S;
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        cin >> input;
        a.push_back(input);
    }
    
    printf("%d", ckstring(0, S, a));

    return 0;
}