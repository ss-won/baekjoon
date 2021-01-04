#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 1001;
int n;
int memo[MAX];
int bnext[MAX];

int getlis(int start, vector<int> arr){
    int mx = 1, nx = -1;
    if(memo[start] != 0)
        return memo[start];
    for(int i=start+1;i<n;i++){
        if(arr[start] < arr[i]){
            int mid = getlis(i, arr) + 1;
            if(mid > mx){
                mx = mid;
                nx = i;
            }
        }
    }
    bnext[start] = nx;
    return memo[start] = mx;
}

void setlis(int start, vector<int> arr, vector<int>& lis){
    if(bnext[start] == 0) return;
    lis.push_back(arr[start]);
    setlis(bnext[start], arr, lis);
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    int num, res = 0, mi = 0;
    vector<int> arr;
    vector<int> lis;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> num;
        arr.push_back(num);
    }
    for(int i=0;i<n;i++){
        if(n-i > res){
            int mid = getlis(i, arr);
            if(mid > res){
                res = mid;
                mi = i;
            }
        }
    }
    cout << res << "\n";
    setlis(mi, arr, lis);
    for(int i=0;i<res;i++){
        cout << lis[i] << " ";
    }
    return 0;
}
