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
    vector<ll> a(n), b(n);
    for(auto& e: a){
        cin >> e;
    }
    for(auto& e: b){
        cin >> e;
    }
    ll ans = abs(a[0]-b[0]) + abs(a[n-1]-b[n-1]);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll a2 = 0;
    vector<vector<int>> cnt(2, vector<int>(n, 0));
    for(int i = 0; i<n; i++){
        int j = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        // if(j == 0){
        //     a2 += abs(b[j]-a[i]);
        //     cnt[1][j]++;
        // }
        // else if(j == n){
        //     a2 += abs(a[i]-b[j-1]);
        //     cnt[1][j-1]++;
        // }
        if(j<n){
            a2 += abs(a[i]-b[j]);
            cnt[1][j]++;
        }
        cnt[0][i]++;
    }

    for(int i = 0; i<n; i++){
        if(cnt[1][i] == 0){
            int j = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
            if(j<n){
                a2 += abs(b[i]-a[j]);
                // cnt[1][j]++;
            }
            // cnt[0][i]++;
        }
    }

    cout << min(a2, ans) << nl;

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