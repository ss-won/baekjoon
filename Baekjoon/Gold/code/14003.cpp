#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;
int n, input;
vector<int> arr;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    int res = 1;
    cin >> n;
    vector<int> idx(n, 0);
    for(int i=0;i<n;i++){
        cin >> input;
        arr.push_back(input);
    }
    
    vector<int> c(1, -1000000001);
    for(int i=0;i<(int)arr.size();i++){
        if(c.back() < arr[i]){
            c.push_back(arr[i]);
            idx[i] = (int)c.size()-1;
        }
        else{
            auto it = lower_bound(c.begin(), c.end(), arr[i]);
            *it = arr[i];
            idx[i] = (int)(it - c.begin());
        }
    }
    
    res = (int)c.size()-1;
    cout << res << endl;
    
    vector<int> lis;
    for(int i=n;i>=0;i--){
        if(res <= 0) break;
        if(idx[i] == res){
            lis.push_back(arr[i]);
            res--;
        }
    }
    reverse(lis.begin(), lis.end());
    for(auto num : lis){
        cout << num << " ";
    }
    return 0;
}
