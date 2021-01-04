#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool ckVPS(string str) {
    vector <char> ps;
    for(int i=0;i<str.length();i++){
        if(str[i] == '('){
            ps.push_back('(');
        }
        else {
            if(ps.empty())
                return false;
            else
                ps.pop_back();
        }
    }
    if(!ps.empty())
        return false;
    return true;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    string ps;
    cin >> t;
    while(t--){
        cin >> ps;
        if(ckVPS(ps) == true)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}