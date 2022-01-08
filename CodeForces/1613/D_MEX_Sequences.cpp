// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

ll mod = 998244353;

ll modpow(ll a, ll n){
    if(n == 0) return 1;
    if(n == 1) return a;
    ll half = modpow(a, n/2);
    half = ((half%mod)*(half%mod))%mod;
    if(n%2==0){
        return half;
    }   
    else{
        return ((a%mod)&(half%mod))%mod;
    }
}

int solve(){
    int n;
    cin >> n;
    vector<ll> arr(n);
    for(auto& e: arr){
        cin >> e;
    }
    unordered_map<int,int> h;
    ll ans = 0;
    vector<int> mex(n);
    mex[0] = (arr[0]==0)?1:0;
    for(int i = 0; i<n; i++){
        int m = mex[i];
        if(i){
            if(arr[i]==mex[i-1]){
                m = mex[i] = mex[i-1]+1;
            }
            else{
                m = mex[i] = mex[i-1];
            }
        }

        if(arr[i]<=m){
            for(int j = +1; j>=-1; j--){
                int nm = arr[i]+j;
                if(nm<=m){
                    if(h[nm]>0 && nm>0){
                        ll prod = 1;
                        ll sum = 0;
                        for(int k = nm; k>=0; k--){
                            prod = ((prod%mod)*(h[k]%mod))%mod;
                            sum += h[k];
                        }
                        ll x = ((prod%mod)*(modpow(2,sum)%mod))%mod;
                        ans = ((ans%mod) + (x%mod))%mod;
                    }
                    else if(h[nm]>0){
                        ll prod = 1;
                        ll sum = 0;
                        for(int k = nm; k>=0; k--){
                            //prod = ((prod%mod)*(h[k]%mod))%mod;
                            sum += h[k];
                        }
                        ll x = ((prod%mod)*(modpow(2,sum)%mod))%mod;
                        ans = ((ans%mod) + (x%mod))%mod;
                    }
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}

int main(){
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}