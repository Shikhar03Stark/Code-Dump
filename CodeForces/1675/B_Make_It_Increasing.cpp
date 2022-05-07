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
    ll ans = 0;
    for(int i = n-2; i>=0; i--){
        while(arr[i] >= arr[i+1]){
            arr[i] /= 2;
            ans++;
            if(arr[i]/2 == arr[i]){
                break;
            }
        }
        if(arr[i] >= arr[i+1]){
            cout << -1 << nl;
            return;
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