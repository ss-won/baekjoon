#include <iostream>
#include <functional>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
using namespace std;
string answer = "123456780";
string puzzle;
int s;
set<string> com;
int mv[] = {-1, 1, -3, 3};

string swap(string s, int i, int j){
    char tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
    return s;
}

bool visited(string s){
    if(com.find(s) != com.end())
        return true;
    return false;
}

void bfs(){
    queue<tuple<string, int, int>> q;
    q.push({puzzle, s, 0});
    com.insert(puzzle);
    while(!q.empty()){
        string c, n; int pos, d;
        tie(c, pos, d) = q.front(); q.pop();
        if(c == answer){
            cout << d;
            return;
        }
        // 상
        if(pos-3 >= 0){
            n = swap(c,pos,pos-3);
            if(!visited(n)){
                com.insert(n);
                q.push({n, pos-3, d+1});
            }
        }
        //하
        if(pos+3 < 9){
            n = swap(c, pos, pos+3);
            if(!visited(n)){
                com.insert(n);
                q.push({n, pos+3, d+1});
            }
        }
        
        // 좌우
        if(pos >= 0 && pos < 3){
            if(pos-1 >= 0 && pos-1 < 3){
                n = swap(c, pos, pos-1);
                if(!visited(n)){
                    com.insert(n);
                    q.push({n, pos-1, d+1});
                }
            }
            if(pos+1 >= 0 && pos+1 < 3){
                n = swap(c, pos, pos+1);
               if(!visited(n)){
                   com.insert(n);
                   q.push({n, pos+1, d+1});
               }
            }
        }
        else if(pos >= 3 && pos < 6){
            if(pos-1 >= 3 && pos-1 < 6){
                n = swap(c, pos, pos-1);
                if(!visited(n)){
                    com.insert(n);
                    q.push({n, pos-1, d+1});
                }
            }
            if(pos+1 >= 3 && pos+1 < 6){
                n = swap(c, pos, pos+1);
               if(!visited(n)){
                   com.insert(n);
                   q.push({n, pos+1, d+1});
               }
            }
        }
        else{
            if(pos-1 >= 6 && pos-1 < 9){
                n = swap(c, pos, pos-1);
                if(!visited(n)){
                    com.insert(n);
                    q.push({n, pos-1, d+1});
                }
            }
            if(pos+1 >= 6 && pos+1 < 9){
                n = swap(c, pos, pos+1);
               if(!visited(n)){
                   com.insert(n);
                   q.push({n, pos+1, d+1});
               }
            }
        }
    }
    cout << -1;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    char input;
    for(int i=0;i<9;i++){
        cin >> input;
        if(input == '0') s = i;
        puzzle += input;
    }
    bfs();
    return 0;
}
