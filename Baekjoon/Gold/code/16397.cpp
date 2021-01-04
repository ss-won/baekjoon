#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
using namespace std;
int n, t, g;
bool visited[100000];

int a(int n){
    return n+1;
}

int b(int n){
    int nn = 2*n;
    int s = (int)to_string(nn).length();
    int ten = 1;
    for(int i=1;i<=s-1;i++){
        ten *= 10;
    }
    return (nn/ten-1)*ten + nn%ten;
}

void bfs(){
    int c, r;
    queue<pair<int,int>> q;
    if(n >= 50000){
        if(n == g){
            cout << 0;
            return;
        }
        if(n > g){
            cout << "ANG";
            return;
        }
        else{
            if(g-n <= t){
                cout << g-n;
                return;
            }
            else{
                cout << "ANG";
                return;
            }
        }
    }
    
    visited[n] = true;
    q.push({n,0});
    while(!q.empty()){
        tie(c, r) = q.front(); q.pop();
        if(c == g){
            cout << r;
            return;
        }
        if(r > t) break;
        int ac = a(c), bc = 0;
        if(ac == g && r+1 <= t){
            cout << r+1;
            return;
        }
        if(ac < g && !visited[ac]){
            q.push({ac, r+1});
            visited[ac] = true;
        }
        
        if(c!=0 && c < 50000){
            bc = b(c);
            if(bc == g && r+1 <= t){
                cout << r+1;
                return;
            }
            if(!visited[bc]){
                q.push({bc, r+1});
                visited[bc] = true;
            }
        }
    }
    cout << "ANG";
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> t >> g;
    bfs();
    return 0;
}
