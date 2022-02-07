// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

bool pos(ll x, vector<ll> &a, vector<ll> &b, ll k){
    ll reqg = 0;
    int n = a.size();
    for(int i = 0; i<n; i++){
        reqg += max(0LL, a[i]*x - b[i]);
        if(reqg>k) return false;
    }
    return true;
}

void solve(){
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), b(n);
    for(auto& e: a){
        cin >> e;
    }
    for(auto& e: b){
        cin >> e;
    }

    ll low = 0, high = k+*max_element(b.begin(), b.end())+10;
    while(low<=high){
        ll mid = low+(high-low)/2;
        if(pos(mid, a, b, k)){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }

    cout << high << nl;

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