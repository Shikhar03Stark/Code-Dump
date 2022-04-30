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
    ll n, m;
    cin >> n >> m;
    vector<ll> arr(n);
    map<ll, ll> h;
    for(auto& e: arr){
        cin >> e;
        h[e]++;
    }
    sort(arr.rbegin(), arr.rend());
    vector<ll> uniq;
    uniq.push_back(arr[0]);
    for(int i = 0; i<n; i++){
        if(uniq.back() != arr[i]){
            uniq.push_back(arr[i]);
        }
    }

    int n2 = uniq.size();
    if(n2 == 1){
        if(h[uniq[0]]*(uniq[0]+1) <= m){
            cout << "YES" << nl;
        }
        else{
            cout << "NO" << nl;
        }
        return;
    }
    for(int i = 0; i<n2; i++){
        if(i==0){
            m -= (h[uniq[i]] + 1)*uniq[i] + h[uniq[i]];
        }
        else if(i == n2-1){
            m -= (h[uniq[i]] - 1)*uniq[i] + h[uniq[i]];
        }
        else{
            m -= (h[uniq[i]])*uniq[i] + h[uniq[i]];
        }
        if(m < 0){
            cout << "NO" << nl;
            return;
        }
    }
    cout << "YES" << nl;
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