// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto& e: arr){
        cin >> e;
    }
    long long S = 0;
    vector<ll> prefix(n,0);
    vector<int> thirds(n,0);
    for(int i = 0; i<n; i++){
        if(i){
            prefix[i] = arr[i] + prefix[i-1];
        }
        else{
            prefix[i] = arr[i];
        }
    }
    S = prefix[n-1];
    for(int i = 0; i<n; i++){
        if(3*prefix[i] == S){
            if(i){
                thirds[i] = thirds[i-1]+1;
            }
            else{
                thirds[i] = 1;
            }
        }
        else{
            if(i){
                thirds[i] = thirds[i-1];
            }
        }
    }
    // for(int i = 0; i<n; i++){
    //     cout << prefix[i] << ":" << thirds[i] << " ";
    // }
    // cout << nl;
    long long ans = 0;
    for(int j = 1; j<n-1; j++){
        if(3*prefix[j]%2==0 && 3*prefix[j]/2 == S){
            int ci = thirds[j-1];
            ans += ci;
            //cerr << j << " " << ci << nl;
        }
    }

    cout << ans << nl;

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