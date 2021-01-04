#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n, k, l, mv_id = 0, t=1;
int sx = 1, sy = 1, tx=1, ty=1; // 뱀의 머리&꼬리 x, y 좌표(초기값은 1,1)
char map[101][101];
bool finished = false;
queue<pair<int, char>> q;
queue<pair<int,int>> snake;
pair<int,int> mv[] = {{0,1},{1,0},{0,-1},{-1,0}}; // 우, 상, 좌, 하

void mvsnake(){
    if(q.front().first+1 == t){
        // *방향 전환하는 경우*
        if(q.front().second == 'D'){
            if(mv_id + 1 > 3) mv_id = 0;
            else mv_id += 1;
        }
        else{
            if(mv_id - 1 < 0) mv_id = 3;
            else mv_id -= 1;
        }
        q.pop();
    }
    // *앞으로 이동하는 경우*
    sx = sx+mv[mv_id].first; sy = sy+mv[mv_id].second;
    // 앞으로 가는 길이 벽 또는 뱀의 몸통일 때는 finished = true로 하고 이동 종료
    if(sx <= 0 || sx > n || sy <= 0 || sy > n || map[sx][sy] == '1'){
        finished = true;
        return;
    }
    // 뱀의 길이를 1 늘려 이동
    if(map[sx][sy] == 'A'){
        // 해당 칸에 사과가 있으면 그대로 유지
        map[sx][sy] = '1';
        snake.push({sx,sy});
    }
    else{
        // 해당 칸에 사과가 없을때는 뱀의 길이 중 마지막 칸 0으로 바꾸기
        map[sx][sy] = '1';
        map[tx][ty] = '0';
        snake.push({sx,sy});
        snake.pop();
        // tail의 좌표값 갱신
        tx = snake.front().first;
        ty = snake.front().second;
    }
}

void gamestart(){
    while(!finished){
       // 스네이크 이동
        mvsnake();
        if(finished)
            break;
       // t 증가
        t++;
    }
    cout << t;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    int x, y, st; char r;
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        fill(&map[i][1],&map[i][n]+1, '0');
    }
    // 사과 위치 map에 기록
    while(k--){
        cin >> x >> y;
        map[x][y] = 'A';
    }
    
    // 뱀의 방향 전환 리스트 큐에 넣기
    cin >> l;
    while(l--){
        cin >> st >> r;
        q.push({st, r});
    }
    
    //뱀 위치 초기화
    map[1][1] = '1';
    snake.push({1,1});
    // 게임 시작
    gamestart();
    
    return 0;
}
