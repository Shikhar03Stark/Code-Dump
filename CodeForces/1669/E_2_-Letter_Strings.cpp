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
    vector<string> arr(n);
    for(auto& e: arr){
        cin >> e;
    }
    map<char, ll> fi, se;
    map<string, ll> b;
    ll ans = 0;
    for(int i = 0; i<n; i++){
        char f = arr[i][0], s = arr[i][1];
        ans += fi[f] + se[s] - 2*b[arr[i]];
        fi[f]++;
        se[s]++;
        b[arr[i]]++;
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