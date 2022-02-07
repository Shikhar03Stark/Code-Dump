// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

void solve(){
    ll n, x, y;
    cin >> n >> x >> y;
    vector<ll> arr(n);
    ll nodd = 0;

    for(auto& e: arr){
        cin >> e;
        nodd += (e%2==1?1:0);
    }
    if(y%2==1){
        if(x%2==1){
            if(nodd%2==0){
                cout << "Alice" << nl;
            }
            else{
                cout << "Bob" << nl;
            }
        }
        else{
            if(nodd%2==0){
                cout << "Bob" << nl;
            }
            else{
                cout << "Alice" << nl;
            }
        }
    }
    else{
        if(x%2==1){
            if(nodd%2==0){
                cout << "Bob" << nl;
            }
            else{
                cout << "Alice" << nl;
            }
        }
        else{
            if(nodd%2==0){
                cout << "Alice" << nl;
            }
            else{
                cout << "Bob" << nl;
            }
        }
    }
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