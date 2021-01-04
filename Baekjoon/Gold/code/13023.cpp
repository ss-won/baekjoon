#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#define MAX 2000
using namespace std;
int n, m, u, v;
int e, len = 0;
vector<int> adj[MAX];
bool visited[MAX];
bool res = false;

void dfs(int start, int l){
    if(l==5) {
        res = true;
        return;
    }
    if(l > len){
        e = start;
        len = l;
    }
    for(int i=0;i<(int)adj[start].size();i++){
        if(!visited[adj[start][i]]){
            if(res) break;
            visited[start] = true;
            dfs(adj[start][i], l+1);
            visited[start] = false;
        }
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    
    for(int i=0;i<m;i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    fill(&visited[0], &visited[n]+1, false);
    visited[0] = true;
    dfs(0,1);
    
    if(!res){
        fill(&visited[0], &visited[n]+1, false);
        visited[e] = true;
        dfs(e,1);
    }
    
    cout << res;
    return 0;
}
