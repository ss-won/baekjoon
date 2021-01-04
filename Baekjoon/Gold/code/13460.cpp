#include <iostream>
#include <functional>
#include <algorithm>
#include <queue>
using namespace std;
int n, m, rx, ry, bx, by;
pair<int,int> h, r, b; // 구멍의 위치, 빨간 구슬 위치, 파란 구슬 위치
char map[10][11];
bool visited[10][10][10][10];
pair<int,int> mv[] = {{1,0},{-1,0},{0,1},{0,-1}};

pair<pair<int,int>,pair<int,int>> right(pair<int,int> r, pair<int,int> b){
    tie(rx, ry) = r; tie(bx, by) = b;
    while(rx != bx || ry != by){
        if(by+1 > 0 && by+1 < m-1 && ry+1 > 0 && ry+1 < m-1 && map[bx][by+1] != '#' && map[rx][ry+1] != '#'){
                if(rx == bx && ry+1 == by+1) break;
                ry += 1; by += 1;
                if(rx == h.first && ry == h.second){
                    if(rx == bx){
                        int tmp = by;
                        while(tmp < m-1){
                            if(map[bx][tmp] == '#')
                                break;
                            if(map[bx][tmp] == 'O')
                                return {r, b};
                            tmp++;
                        }
                    }
                    break;
                }
                if(bx == h.first && by == h.second){
                    return {r, b};
                }
        }
        else if(by+1 > 0 && by+1 < m-1 && map[bx][by+1] != '#' && (ry+1 == 0 || ry+1 == m-1 || map[rx][ry+1] == '#')){
                if(rx == bx && ry == by+1) break;
                by += 1;
                if(bx == h.first && by == h.second){
                    return {r, b};
                }
        }
        else if(ry+1 > 0 && ry+1 < m-1 && map[rx][ry+1] != '#' && (by+1 == 0 || by+1 == m-1 || map[bx][by+1] == '#')){
                if(rx == bx && ry+1 == by) break;
                ry += 1;
                if(rx == h.first && ry == h.second){
                    break;
                }
        }
        else
            break;
    }
    return {{rx, ry}, {bx, by}};
}

pair<pair<int,int>,pair<int,int>> left(pair<int,int> r, pair<int,int> b){
    tie(rx, ry) = r; tie(bx, by) = b;
    while(rx != bx || ry != by){
        if(by-1 > 0 && by-1 < m-1 && ry-1 > 0 && ry-1 < m-1 && map[bx][by-1] != '#' && map[rx][ry-1] != '#'){
                if(rx == bx && ry-1 == by-1) break;
                ry -= 1; by -= 1;
                if(rx == h.first && ry == h.second){
                    if(rx == bx){
                        int tmp = by;
                        while(tmp > 0){
                            if(map[bx][tmp] == '#')
                                break;
                            if(map[bx][tmp] == 'O')
                                return {r, b};
                            tmp--;
                        }
                    }
                    break;
                }
                if(bx == h.first && by == h.second){
                    return {r, b};
                }
        }
        else if(by-1 > 0 && by-1 < m-1 && map[bx][by-1] != '#' &&(ry-1 == 0 || ry-1 == m-1 || map[rx][ry-1] == '#')){
                if(rx == bx && ry == by-1) break;
                by -= 1;
                if(bx == h.first && by == h.second){
                    return {r, b};
                }
        }
        else if(ry-1 > 0 && ry-1 < m-1 && map[rx][ry-1] != '#' && (by-1 == 0 || by-1 == m-1 || map[bx][by-1] == '#')){
                if(rx == bx && ry-1 == by) break;
                ry -= 1;
                if(rx == h.first && ry == h.second){
                    break;
                }
        }
        else
            break;
    }
    return {{rx, ry}, {bx, by}};
}

pair<pair<int,int>,pair<int,int>> up(pair<int,int> r, pair<int,int> b){
    tie(rx, ry) = r; tie(bx, by) = b;
    while(rx != bx || ry != by){
        if(bx-1 > 0 && bx-1 < n-1 && rx-1 > 0 && rx-1 < n-1 && map[bx-1][by] != '#' && map[rx-1][ry] != '#'){
                if(rx-1 == bx-1 && ry == by) break;
                rx -= 1; bx -= 1;
                if(rx == h.first && ry == h.second){
                    if(ry == by){
                        int tmp = bx;
                        while(tmp > 0){
                            if(map[tmp][by] == '#')
                                break;
                            if(map[tmp][by] == 'O')
                                return {r, b};
                            tmp--;
                        }
                    }
                    break;
                }
                if(bx == h.first && by == h.second){
                    return {r, b};
                }
        }
        else if(bx-1 > 0 && bx-1 < n-1 && map[bx-1][by] != '#' && (rx-1 == 0 || rx-1 == n-1 || map[rx-1][ry] == '#')){
                if(rx == bx-1 && ry == by) break;
                bx -= 1;
                if(bx == h.first && by == h.second){
                    return {r, b};
                }
        }
        else if(rx-1 > 0 && rx-1 < n-1 && map[rx-1][ry] != '#' &&(bx-1 == 0 || bx-1 == n-1 || map[bx-1][by] == '#')){
                if(rx-1 == bx && ry == by) break;
                rx -= 1;
                if(rx == h.first && ry == h.second){
                    break;
                }
        }
        else
            break;
    }
    return {{rx, ry}, {bx, by}};
}

pair<pair<int,int>,pair<int,int>> down(pair<int,int> r, pair<int,int> b){
    tie(rx, ry) = r; tie(bx, by) = b;
    while(rx != bx || ry != by){
        if(bx+1 > 0 && bx+1 < n-1 && rx+1 > 0 && rx+1 < n-1 && map[bx+1][by] != '#' && map[rx+1][ry] != '#'){
            if(rx+1 == bx+1 && ry == by) break;
            rx += 1; bx += 1;
            if(rx == h.first && ry == h.second){
                if(ry == by){
                    int tmp = bx;
                    while(tmp < n-1){
                        if(map[tmp][by] == '#')
                            break;
                        if(map[tmp][by] == 'O')
                            return {r, b};
                        tmp++;
                    }
                }
                break;
            }
            if(bx == h.first && by == h.second){
                return {r, b};
            }
        }
        else if(bx+1 > 0 && bx+1 < n-1 && map[bx+1][by] != '#' && (rx+1 <= 0 || rx+1 >= n-1 || map[rx+1][ry] == '#')){
                if(rx == bx+1 && ry == by) break;
                bx += 1;
                if(bx == h.first && by == h.second){
                    return {r, b};
                }
        }
        else if(rx+1 > 0 && rx+1 < n-1 && map[rx+1][ry] != '#' &&(bx+1 <= 0 || bx+1 >= n-1 || map[bx+1][by] == '#')){
                if(rx+1 == bx && ry == by) break;
                rx += 1;
                if(rx == h.first && ry == h.second){
                    break;
                }
        }
        else
            break;
    }
    return {{rx, ry}, {bx, by}};
}

void bfs(){
    queue<tuple<pair<int,int>,pair<int,int>,int>> q;
    visited[r.first][r.second][b.first][b.second] = true;
    q.push({r, b, 0});
    while(!q.empty()){
        int d;
        tie(r, b, d) = q.front(); q.pop();
        tie(rx, ry) = r; tie(bx, by) = b;
        pair<int,int> nr, nb;
            tie(nr, nb) = right(r, b);
            if(!visited[nr.first][nr.second][nb.first][nb.second] && d+1 <= 10){
                if(nr.first == h.first && nr.second == h.second){
                    cout << d+1;
                    return;
                }
                q.push({nr, nb, d+1});
                visited[nr.first][nr.second][nb.first][nb.second] = true;
            }
            tie(nr, nb) = left(r, b);
            if(!visited[nr.first][nr.second][nb.first][nb.second] && d+1 <= 10){
                if(nr.first == h.first && nr.second == h.second){
                    cout << d+1;
                    return;
                }
                q.push({nr, nb, d+1});
                visited[nr.first][nr.second][nb.first][nb.second] = true;
            }
            tie(nr, nb) = up(r, b);
            if(!visited[nr.first][nr.second][nb.first][nb.second] && d+1 <= 10){
                if(nr.first == h.first && nr.second == h.second){
                    cout << d+1;
                    return;
                }
                q.push({nr, nb, d+1});
                visited[nr.first][nr.second][nb.first][nb.second] = true;
            }
            tie(nr, nb) = down(r, b);
            if(!visited[nr.first][nr.second][nb.first][nb.second] && d+1 <= 10){
                if(nr.first == h.first && nr.second == h.second){
                    cout << d+1;
                    return;
                }
                q.push({nr, nb, d+1});
                visited[nr.first][nr.second][nb.first][nb.second] = true;
            }
    }
    cout << -1;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> map[i];
        for(int j=0;j<m;j++){
            if(map[i][j] == 'O'){
                h = {i, j};
            }
            else if(map[i][j] == 'R'){
                r = {i, j};
            }
            else if(map[i][j] == 'B'){
                b = {i, j};
            }
        }
    }
    bfs();
    return 0;
}
