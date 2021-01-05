#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 101;
bool finished = false;
bool visited[MAX];

int countParent(int s, int e, vector<int> *adj) {
    int v, count = 0;
    queue<pair<int,int>> q;
    visited[s] = true;
    q.push({s, 0});
    while(!q.empty()){
        tie(v, count) = q.front(); q.pop();
        if(v==e){
            finished = true;
            break;
        }
        for(auto nv : adj[v]) {
            if(!visited[nv]){
                visited[nv] = true;
                q.push({nv, count+1});
            }
        }
    }
    return (finished) ? count : -1;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    int n, p1, p2, m, p, c;
    cin >> n >> p1 >> p2 >> m;
    
    vector<int> adj[n+1];
    while(m--) {
        cin >> p >> c;
        adj[p].push_back(c);
        adj[c].push_back(p);
    }

    cout << countParent(p1, p2, adj);
    return 0;
}