#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int n, input;
priority_queue<int, vector<int>, greater<int>> mnq;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=0;i<n*n;i++){
        cin >> input;
        mnq.push(input);
        if(mnq.size() > n)
            mnq.pop();
    }
    cout << mnq.top();
    return 0;
}