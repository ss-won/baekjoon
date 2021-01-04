#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
using namespace std;
int t, m, input, c = 0;
priority_queue<int, vector<int>, less<int>> mxq;
priority_queue<int, vector<int>, greater<int>> mnq;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--){
        cin >> m;
        priority_queue<int, vector<int>, less<int>> mxq;
        priority_queue<int, vector<int>, greater<int>> mnq;
        c = 0;
        cout << (m/2)+1 << "\n";
        for(int i=1;i<=m;i++){
            cin >> input;
            if(mxq.empty() && mnq.empty()){
                mxq.push(input);
            }
            else if(mxq.size() > mnq.size()){
                if(mxq.top() > input){
                    mxq.push(input);
                    mnq.push(mxq.top()); mxq.pop();
                }
                else{
                    mnq.push(input);
                }
            }
            else if(mxq.size() == mnq.size()){
                if(mxq.top() < input){
                    mnq.push(input);
                    mxq.push(mnq.top()); mnq.pop();
                }
                else{
                    mxq.push(input);
                }
            }
            if(i%2==1){
                cout << mxq.top() << " ";
                c++;
                if(c % 10 == 0) cout << "\n";
            }
        }
        cout << "\n";
    }
    return 0;
}
