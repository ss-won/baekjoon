#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX = 100001;
bool visited[MAX];
int path[MAX];
int n, k;

void printPath(int cur) {
    if(cur == path[cur]){
        cout << cur << " ";
        return;
    }
    printPath(path[cur]);
    cout << cur << " ";
}

void bfs(int start) {
    int v, t, next[3];
    queue<pair<int,int>> q;
    visited[start] = true;
    path[start] = start;
    q.push({start, 0});
    while(!q.empty()){
        tie(v, t) = q.front(); q.pop();
        if(v == k){
            cout << t << "\n";
            printPath(k);
            return;
        }
        next[0] = v+1; next[1] = v-1; next[2] = v*2;
        for(int i=0;i<3;i++){
            if(next[i] >= 0 && next[i] < MAX && !visited[next[i]]){
                path[next[i]] = v; // 이전 경로 저장
                q.push({next[i], t+1});
                visited[next[i]] = true;
            }
        }
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    fill(&visited[0], &visited[MAX], false);
    bfs(n);
    return 0;
}
