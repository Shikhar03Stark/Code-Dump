// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

bool isgood(ll n, ll k, ll v){
    ll lines = 0;
    while(v){
        lines += v;
        //cerr << v << " ";
        v /= k;
    }

    if( lines >= n) return true;
    return false;
}

int solve(){
    ll n, k;
    cin >> n >> k;
    ll low = 1, high = n;
    while(low<=high){
        ll mid = low + (high-low)/2;
        if(isgood(n, k, mid)){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    cout << low << endl;
    return 0;
}

int main(){
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}