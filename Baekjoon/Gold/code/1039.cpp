#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
using namespace std;
int n, k, m;
int tenth[6] = {1, 10, 100, 1000, 10000, 100000};
bool visited[1000001][11];

bool canswap(int num, int i, int j){
    int jn = (num/tenth[m-j])%10;
    if(i==1 && jn == 0) return false;
    return true;
}

int swap(int num, int i, int j){
    int in = (num/tenth[m-i])%10;
    int jn = (num/tenth[m-j])%10;
    if(i==1 && jn == 0) return -1;
    num -= in * tenth[m-i] + jn * tenth[m-j];
    num += in * tenth[m-j] + jn * tenth[m-i];
    return num;
}

void bfs(){
    queue<pair<int,int>> q;
    q.push({n, 0});
    visited[n][0] = true;
    int c, len, mx = 0;
    while(!q.empty()){
        tie(c, len) = q.front(); q.pop();
        if(len == k){
            mx = max(c,mx);
        }
        if(len < k){
            for(int i=1;i<=m;i++){
                for(int j=i+1;j<=m;j++){
                    int next = 0;
                    if(canswap(c, i, j)){
                        next = swap(c,i,j);
                        if(!visited[next][len+1]){
                            visited[next][len+1] = true;
                            q.push({next, len+1});
                        }
                    }
                }
            }
        }
    }
    if(mx == 0) cout << -1;
    else cout << mx;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    m = (int)to_string(n).length();
    bfs();
    return 0;
}