#include <iostream>
#include <string>
#include <vector>
#define MAX 1000001
using namespace std;
int L;
string S;
vector<int> failure(MAX, 0);

void getFailure(){
    int n = (int)S.length(), j = 0;
    for(int i=1;i<n;i++){
        while(j > 0 && S[i] != S[j])
            j = failure[j-1];
        if(S[i] == S[j])
            failure[i] = ++j;
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cin >> L >> S;
    getFailure();
    
    cout << S.length()-failure[S.length()-1];
    return 0;
}