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
    for(int i = 0; i<(1<<n); i++){
        ll sum = 0;
        for(int j = 0; j<n; j++){
            if((i&(1<<j)) > 0){
                sum -= arr[j];
            }
            else{
                sum += arr[j];
            }
        }
        if(sum%360 == 0){
            cout << "YES" << nl;
            return;
        }
    }
    cout << "NO" << nl;
    
    return;
}

int main(){
    FASTIO
    pre();
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}