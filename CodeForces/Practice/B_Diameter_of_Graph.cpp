// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

void solve(){
    ll n, m, k;
    cin >> n >> m >> k;
    if(m < n-1){
        cout << "NO" << nl;
        return;
    }
    if(m>n*(n-1)/2){
        cout << "NO" << nl;
        return;
    }
    if(n==1){
        if(m<1 && k>1){
            cout << "YES" << nl;
        }
        else{
            cout << "NO" << nl;
        }
        return;
    }
    if(m==n*(n-1)/2){
        if(k>=3){
            cout << "YES" << nl;
        }
        else{
            cout << "NO" << nl;
        }
        return;
    }
    if(m<n*(n-1)/2){
        if(k>3){
            cout << "YES" << nl;
        }
        else{
            cout << "NO" << nl;
        }
        return;
    }
    cout << "NO" << nl;
    return;
}

int main(){
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}