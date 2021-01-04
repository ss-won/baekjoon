#include <iostream>
#include <algorithm>
#include <functional>
#include <limits>
#include <queue>
#define MAX 20001
using namespace std;
int V, E, u, v, w, d, start;
float distances[MAX];
float inf = numeric_limits<float>::infinity();
struct compare{
    bool operator()(pair<int,int> a, pair<int,int> b){
        return a.second > b.second;
    }
};
vector<pair<int,int>> adj[MAX];
priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq;

void dijkstra(){
    pq.push({start,0});
    fill(&distances[1], &distances[V]+1, inf);
    distances[start] = 0;
    
    while(!pq.empty()){
        tie(v, w) = pq.top(); pq.pop();
        for(auto i=0;i<adj[v].size();i++){
            tie(u, d) = adj[v][i];
            if(distances[u] > w+d){
                distances[u] = w+d;
                pq.push({u, w+d});
            }
        }
    }
    
    for(int i=1;i<=V;i++){
        if(distances[i] == inf)
            cout << "INF\n";
        else
            cout << distances[i] << "\n";
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> V >> E >> start;
    for(int i=0;i<E;i++){
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
    }
    
    dijkstra();
    return 0;
}