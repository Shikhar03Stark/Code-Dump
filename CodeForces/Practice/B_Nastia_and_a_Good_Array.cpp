// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

void pre(){
    
    return;
}

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto& e: arr){
        cin >> e;
    }
    int mini = 0;
    for(int i = 0; i<n; i++){
        if(arr[mini] > arr[i]){
            mini = i;
        }
    }
    cout << n-1 << nl;
    for(int i = 0; i<n; i++){
        if(i != mini){
            if(i%2 == mini%2){
                cout << i+1 << " " << mini+1 << " " <<  arr[mini] << " " << arr[mini] << nl;
            }
            else{
                cout << i+1 << " " << mini+1 << " " <<  arr[mini]+1 << " " << arr[mini] << nl;
            }
        }
    }
    return;
}

int main(){
    FASTIO
    pre();
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}