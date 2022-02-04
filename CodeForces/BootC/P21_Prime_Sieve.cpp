// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

void solve(){
    int n;
    cin >> n;
    //int cnt = 0;
    vector<bool> prime(n+5, true);
    vector<int> ans;
    for(ll i = 2; i*i<=n; i++){
        if(prime[i]){
            if(i<=n)
            for(ll j = i*i; j<=n; j+=i){
                prime[j] = false;
            }
        }
    }
    for(int i = 2; i<=n; i++){
        if(prime[i])
            ans.push_back(i);
    }
    cout << ans.size() << nl;
    for(auto& e: ans){
        cout << e << " ";
    }
    return;
}

int main(){
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}