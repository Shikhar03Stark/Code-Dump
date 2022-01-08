#include <bits/stdc++.h>
using namespace std;

typedef unsigned long int ui;
typedef long int i;

int main(){
    int t ;
    cin >> t;
    while(t--){
        i n, c;
        cin >> n >> c;
        vector<int> a(n);
        for(int i = 0; i<n;i++){
            cin >> a[i];
        }
        ui sum = 0;
        for(auto &i : a){
            sum += i;
        }
        if(sum <= c){
            cout << "YES" <<endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}