#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;
const int MAX = 101;
int tomato[MAX][MAX][MAX];
tuple<int,int,int> mv[6] = {{1,0,0}, {-1,0,0}, {0,1,0}, {0,-1,0}, {0,0,1}, {0,0,-1}};
int m, n, h;

bool ckFinished() {
    int cnt = 0;
    for(int i=0;i<h;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                if(tomato[i][j][k] == 0)
                    return false;
                if(tomato[i][j][j] == -1)
                    cnt +=1;
            }
        }
    }
    if(cnt == h*n*m)
        return false;
    return true;
}

void bfs(vector<tuple<int,int,int>> &start) {
    queue<tuple<int,int,int,int>> q;
    int z, y, x, t=0;
    bool finished = false;
    for(auto v : start){
        tie(z, y, x) = v;
        q.push({z, y, x, 0});
    }
    while(!q.empty()) {
        tie(z, y, x, t) = q.front(); q.pop();
        for(int i=0;i<6;i++){
            int nz = 0, ny = 0, nx = 0;
            tie(nz, ny, nx) = mv[i];
            nz += z; ny += y; nx += x;
            if(nz >= 0 && nz < h && ny >= 0 && ny < n && nx >= 0 && nx < m){
                if(tomato[nz][ny][nx] == 0){
                    tomato[nz][ny][nx] = t+1;
                    q.push({nz, ny, nx, t+1});
                }
            }
        }
        if(ckFinished()){
            finished = true;
            break;
        }
    }
    (finished) ? cout << t+1 : cout << -1;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    vector<tuple<int,int,int>> start;
    cin >> m >> n >> h;
    for(int i=0;i<h;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                cin >> tomato[i][j][k];
                if(tomato[i][j][k] == 1)
                    start.push_back({i,j,k});
            }
        }
    }
    if(ckFinished())
        cout << 0;
    else
        bfs(start);
    return 0;
}
