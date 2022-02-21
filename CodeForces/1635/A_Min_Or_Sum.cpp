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
    int ans = 0;
    for(int b = 0; b<30; b++){
        for(int i = 0; i<n; i++){
            if((arr[i]&(1<<b)) > 0){
                ans = (ans | (1<<b));
                break;
            }
        }
    }
    cout << ans << nl;
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