#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <deque>
using namespace std;

int main() {
    int N = 0;
    int input = 0;
    string com;
    deque<int> dq;
    
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        cin >> com;
        if(com == "push_front"){
            cin >> input;
            dq.push_front(input);
        }
        else if(com == "push_back"){
            cin >> input;
            dq.push_back(input);
        }
        else if(com == "pop_front"){
            if(!dq.empty()){
                cout << dq.front() << "\n";
                dq.pop_front();
            }
            else{
                cout << -1 << "\n";
            }
        }
        else if(com == "pop_back"){
            if(!dq.empty()){
                cout << dq.back() << "\n";
                dq.pop_back();
            }
            else{
                cout << -1 << "\n";
            }
        }
        else if(com == "size"){
            cout << dq.size() << "\n";
        }
        else if(com == "empty"){
            if(dq.empty())
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }
        else if(com == "front"){
            if(!dq.empty()){
                cout << dq.front() << "\n";
            }
            else{
                cout << -1 << "\n";
            }
        }
        else if(com == "back"){
            if(!dq.empty()){
                cout << dq.back() << "\n";
            }
            else{
                cout << -1 << "\n";
            }
        }
    }
    
    return 0;
}
