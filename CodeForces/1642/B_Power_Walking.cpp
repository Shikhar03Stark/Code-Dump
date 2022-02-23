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
    ll n;
    cin >> n;
    vector<ll> arr(n);
    unordered_map<ll,ll> h;
    for(auto& e: arr){
        cin >> e;
        h[e]++;
    }
    vector<ll> seq;
    for(auto& p: h){
        seq.push_back(p.second);
    }
    int cnt = 0;
    for(int i = 0; i<h.size(); i++){
        cout << h.size() << " ";
        cnt++;
    }
    int p = h.size();
    while(cnt<n){
        cout << (++p) << " ";
        cnt++;
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