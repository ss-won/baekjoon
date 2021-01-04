#include <iostream>
#include <algorithm>
#include <functional>
#include <cstring>
#include <tuple>
#include <queue>
#define MAX 101
using namespace std;
int n, m, h;
char map[MAX][MAX];
bool visited[MAX][MAX];
pair<int,int> mv[4] = {{1,0},{-1,0},{0,1},{0,-1}};
queue<tuple<int,int,int>> q;

void bfs(int x, int y){
    visited[x][y] = true;
    q.push({x,y,1});
    while(!q.empty()){
        tie(x,y,h) = q.front(); q.pop();
        if(x == n-1 && y == m-1){
            cout << h;
            return;
        }
        for(int i=0;i<4;i++){
            int nx = x+mv[i].first, ny = y+mv[i].second;
            if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                if(map[nx][ny] == '1' && !visited[nx][ny]){
                    q.push({nx,ny,h+1});
                    visited[nx][ny] = true;
                }
            }
        }
    }
}

int main() {
    //ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> map[i];
    }
    bfs(0,0);
    return 0;
}