#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
using namespace std;
vector<int> res;

vector<int> getfailure(string p){
    int j = 0;
    vector<int> failure((int)p.length(), 0);
    for(int i=1;i<(int)p.length();i++){
        while(j > 0 && p[i] != p[j])
            j = failure[j-1];
        if(p[i]==p[j]){
            failure[i] = ++j;
        }
    }
    return failure;
}

void kmp(string t, string p){
    vector<int> pi = getfailure(p);
    int j = 0, n = (int)t.length(), m = (int)p.length();
    for(int i=0;i<n;i++){
        while(j>0 && t[i] != p[j])
            j = pi[j-1];
        if(t[i] == p[j]){
            if(j==m-1){
                res.push_back(i-m+2);
                j = pi[j];
            }
            else{
                j++;
            }
        }
    }
}

int main() {
    //ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    string T, P;
    getline(cin, T, '\n');
    getline(cin, P, '\n');
    kmp(T, P);
    cout << (int)res.size() << endl;
    for(auto i=0;i<(int)res.size();i++){
        cout << res[i] << " ";
    }
    return 0;
}