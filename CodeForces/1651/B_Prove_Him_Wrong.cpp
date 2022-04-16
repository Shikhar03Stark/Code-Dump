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
    vector<ll> ans(n, 1);
    for(int i = 1; i<n; i++){
        if(ans[i-1]*3 > 1e9){
            cout << "NO" << nl;
            return;
        }
        ans[i] = ans[i-1]*3;
    }
    cout << "YES" << nl;
    for(int i = 0; i<n; i++){
        cout << ans[i] << " ";
    }
    cout << nl;
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