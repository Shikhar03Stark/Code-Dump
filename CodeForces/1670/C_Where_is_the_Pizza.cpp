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

const ll mod = 1e9+7;

void mark(vector<int> &vis, vector<ll> &a, vector<ll> &b, vector<int> &pa, vector<int> &pb, int idx){
    //mark all b in a
    int p = idx;
    while(vis[p]==0){
        vis[p] = 1;
        p = pa[b[p]];
    }
}

void solve(){
    int n;
    cin >> n;
    vector<ll> a(n), b(n), c(n);
    vector<int> vis(n, 0);
    vector<int> pa(n+1, -1), pb(n+1, -1);
    set<int> done;
    for(int i = 0; i<n; i++){
        cin >> a[i];
        pa[a[i]] = i;
    }
    for(int i = 0; i<n; i++){
        cin >> b[i];
        pb[b[i]] = i;
    }
    for(int i = 0; i<n; i++){
        cin >> c[i];
        if(c[i]!=0){
            done.insert(c[i]);
            mark(vis, a, b, pa, pb, i);
        }
    }
    ll ans = 1;
    for(ll x = 1; x<=n; x++){
        if(done.find(x) == done.end()){
            int posa = pa[x], posb = pb[x];
            if(!vis[posa] && !vis[posb] && posa != posb){
                ans = (ans * 2LL) % mod;
            }
            mark(vis, a, b, pa, pb, posa);
            mark(vis, a, b, pa, pb, posb);
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