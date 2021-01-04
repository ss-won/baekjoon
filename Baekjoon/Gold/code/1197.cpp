#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#define MAX 10001
using namespace std;
int V, E, res=0;
int root[MAX];
int h[MAX];
struct Edges{
    int u;
    int v;
    int w;
};

struct compare{
    bool operator()(Edges a, Edges b){
        return a.w > b.w;
    }
};
priority_queue<Edges, vector<Edges>, compare> pq;

int find(int v){
    if(root[v] != v)
        root[v] = find(root[v]);
    return root[v];
}

void Union(int u, int v){
    int rootu = find(u);
    int rootv = find(v);
    if(h[rootu] > h[rootv]){
       root[rootv] = rootu;
    }
    else{
       if(h[rootu] == h[rootv]){
           h[rootv]++;
       }
       root[rootu] = rootv;
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cin >> V >> E;
    int u, v, w;
    for(int i=1;i<=V;i++){
        root[i] = i;
        h[i] = 1;
    }
    
    for(int i=0;i<E;i++){
        cin >> u >> v >> w;
        pq.push(Edges({u,v,w}));
    }
    
    while(!pq.empty()){
        Edges cur = pq.top(); pq.pop();
        if(find(cur.u) != find(cur.v)){
            Union(cur.u, cur.v);
            res += cur.w;
        }
    }
    cout << res;
    return 0;
}