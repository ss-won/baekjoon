#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 801, MAX_LEN = 200000000;
int n, e, a, b, c, v1, v2;
vector<pair<int,int>> adj[MAX];
int distances[3][MAX];

struct compare{
 bool operator()(pair<int,int> a, pair<int,int> b){
    if(a.second == b.second)
        return a.first > b.first;
    return a.second > b.second;
 }
};

void dijkstra(int s, int id){
    priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq;
    distances[id][s] = 0;
    pq.push({s, distances[id][s]});
    while(!pq.empty()){
        tie(a, c) = pq.top(); pq.pop();
        for(auto b : adj[a]){
            if(distances[id][b.first] > c + b.second){
                distances[id][b.first] = c + b.second;
                pq.push({b.first, distances[id][b.first]});
            }
        }
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    int c1 = 0, c2 = 0;
    cin >> n >> e;
    for(int i=0;i<e;i++){
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    cin >> v1 >> v2;
    
    for(int i=0;i<3;i++){
        fill(&distances[i][0], &distances[i][MAX-1]+1, MAX_LEN);
    }
    
    dijkstra(1, 0);
    dijkstra(v1, 1);
    dijkstra(v2, 2);
    
    c1 =
    (distances[0][v1] != MAX_LEN && distances[1][v2] != MAX_LEN && distances[2][n] != MAX_LEN)
    ? distances[0][v1] + distances[1][v2] + distances[2][n] : -1;
    
    c2 =
    (distances[0][v2] != MAX_LEN && distances[1][n] != MAX_LEN && distances[2][v1] != MAX_LEN)
    ? distances[0][v2] + distances[1][n] + distances[2][v1] : -1;
    
    if(c1 == -1 && c2 == -1){
        cout << -1;
    }
    else if(c1 == -1){
        cout << c2;
    }
    else if(c2 == -1){
        cout << c1;
    }
    else{
        cout << min(c1, c2);
    }
    
    return 0;
}
