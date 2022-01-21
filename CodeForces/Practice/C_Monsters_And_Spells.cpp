// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

ll prefix(ll n){
    return n*(n+1)/2;
}

ll f(vector<ll> &t, vector<ll> &h, int n){
    if(n<0){
        return 0LL;
    }
    if(n==0){
        return prefix(h[n]);
    }
    if(t[n-1] <= t[n] - h[n]){
        return f(t, h, n-1) + prefix(h[n]);
    }
    if(t[n-1] - h[n-1] > t[n] - h[n]){
        return f(t, h, n-1) + prefix(h[n-1] + t[n] - t[n-1]) - prefix(h[n-1]);
    }
    else{
        int j = n-1;
        for(j = n-1; j>=0; j--){
            if((t[j] <= t[n] - h[n]) || (t[j] - h[j] > t[n] - h[n])){
                if(t[j] <= t[n] - h[n]){
                    return f(t, h, j) + prefix(h[n]);
                }
                else{
                    return f(t, h, j) + prefix(h[j]+t[n]-t[j]) - prefix(h[j]);
                }
            }
        }

        return prefix(h[n]);
    }
}

void solve(){
    ll n;
    cin >> n;
    vector<ll> t(n), h(n);
    for(auto& e: t){
        cin >> e;
    }
    for(auto& e: h){
        cin >> e;
    }
    ll edge = n-1;
    ll slack = 0;
    ll ans = 0;
    for(int i = n-1; i>=0; i--){
        if(t[i] <= t[edge] - h[edge]){
            ans += prefix(h[edge]+slack);
            edge = i;
            slack = 0;
            continue;
        }
        if(h[i] > t[i] - t[edge] + h[edge]){
            slack += t[edge] - t[i];
            edge = i;
        }
    }
    ans += prefix(h[edge]+slack);
    cout << ans << nl;
    return;
}

int main(){
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}