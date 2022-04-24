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

vector<ll> factors(ll n){
    vector<ll> ans;
    for(ll i = 1; i*i<=n; i++){
        if(n%i==0){
            if(i == n/i){
                ans.push_back(i);
            }
            else{
                ans.push_back(n/i);
                ans.push_back(i);
            }
        }
    }

    return ans;
}

ll rev(ll n){
    ll ans = 0;
    while(n){
        ans = 10*ans + (n%10);
        n /= 10;
    }
    return ans;
}

void solve(){
    ll n;
    cin >> n;
    ll ans = 0;
    vector<ll> f = factors(n);
    for(auto& e: f){
        // cout << n << " " << rev()
        if(e == rev(e)){
            ans++;
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
    for(int z = 1; z<=T; z++){
        cout << "Case #" << z << ": ";
        solve();
    }
    return 0;
}