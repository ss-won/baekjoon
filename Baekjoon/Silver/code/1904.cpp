#include <iostream>
using namespace std;
const int MAX = 1000001;
int n;
int memo[MAX];

int maxTile(int n){
    if(n==1 || n==2)
        return n;
    if(memo[n] != -1)
        return memo[n];
    return memo[n] = (maxTile(n-1) + maxTile(n-2))% 15746;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    fill(&memo[0], &memo[MAX-1]+1, -1);
    cin >> n;
    cout << maxTile(n);
    return 0;
}
