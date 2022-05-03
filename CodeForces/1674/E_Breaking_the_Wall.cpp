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
    vector<ll> arr(n+2, LLONG_MAX);
    vector<pair<ll,int>> aux;
    ll gmin = LLONG_MAX;
    for(int i = 1; i<=n; i++){
        ll d;
        cin >> d;
        gmin = min(gmin, d);
        aux.push_back({d, i});
        arr[i] = d;
    }
    sort(aux.begin(), aux.end());
    ll ans = LLONG_MAX;
    for(int i = 1; i<=n; i++){
        ll k1 = min({arr[i-1], (ll)ceil(arr[i]/2.0), arr[i+1]});
        ll l2, m2, r2;
        l2 = arr[i-1] - k1;
        m2 = max(0LL,arr[i] - 2*k1);
        r2 = arr[i+1] - k1;
        ll gm = LLONG_MAX;
        for(int j = 0; j<n; j++){
            if(aux[j].second != i && aux[j].second != i-1 && aux[j].second != i+1){
                gm = aux[j].first;
                break;
            }
        }
        if(l2<=0){
            gm = min({gm, m2, r2});
        }
        if(m2<=0){
            gm = min({gm, l2, r2});
        }
        if(r2<=0){
            gm = min({gm, l2, m2});
        }
        ll k2 = ceil(gm/2.0);
        ans = min(ans, k1+k2);
    }
    cout << ans << nl;


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