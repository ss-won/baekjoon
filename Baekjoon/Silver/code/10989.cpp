#include <iostream>
using namespace std;
int num[10001];

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    int n, input;
    cin >> n;
    while(n--){
        cin >> input;
        num[input]++;
    }
    
    for(int i=1;i<=10000;i++){
        if(num[i] > 0){
            for(int j=num[i];j>0;j--)
                cout << i << "\n";
        }
    }
    return 0;
}
