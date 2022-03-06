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
    vector<ll> arr(n);
    for(auto& e: arr){
        cin >> e;
    }
    sort(arr.begin(), arr.end());
    vector<ll> pre(n), suf(n);
    for(int i = 0; i<n; i++){
        if(i){
            pre[i] = pre[i-1] + arr[i];
            suf[n-i-1] = suf[n-i] + arr[n-i-1];
        }
        else{
            pre[i] = arr[i];
            suf[n-i-1] = arr[n-i-1];
        }
    }
    for(int j = n-1; j>=0; j--){
        ll sr = suf[j];
        auto it = lower_bound(pre.begin(), pre.end(), sr);
        if(it-pre.begin()>0){
            it--;
            if((it-pre.begin()+1) > n-j){
                cout << "YES" << nl;
                return;
            }
        }
    }
    cout << "NO" << nl;
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