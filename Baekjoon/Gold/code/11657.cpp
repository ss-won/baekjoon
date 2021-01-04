#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;
const int MAX = 501;
const long long INF = 999999999999999;
int n, m, a, b, c;
vector<pair<int,int>> adj[MAX];

vector<long long> bellmanFord(int start) {
    vector<long long> upper(n+1, INF);
    bool success = false;
    
    upper[start] = 0;
    // V번 순회에서도 업데이트에 성공하면 음수 사이클이 존재한다.
    for(int i=0;i<n;i++){
        success = false;
        for(int cur=1;cur<=n;cur++){
            for(auto next : adj[cur]){
                int v; long long w;
                tie(v, w) = next;
                if(upper[v] > upper[cur] + w && upper[cur] != INF){
                    upper[v] = upper[cur] + w;
                    success = true;
                }
            }
        }
        if(!success) break;
    }
    
    if(success){
        upper.clear();
    }
    else{
        for(int i=2;i<(int)upper.size();i++){
            if(upper[i] == INF)
                upper[i] = -1;
        }
    }
    return upper;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }
    
    if(n==1){
        cout << -1;
        return 0;
    }
    
    vector<long long> ans = bellmanFord(1);
    if(ans.size() == 0){
        cout << -1;
    }
    else{
        for(int i=2;i<=n;i++)
            cout << ans[i] << "\n";
    }
    
    return 0;
}
