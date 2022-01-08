// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

int solve(){
    int n;
    cin >> n;
    vector<ll> arr(n);
    for(auto& e: arr){
        cin >> e;
    }
    ll godd = arr[1], geven = arr[0];
    for(int i = 0; i<n; i+=2){
        geven = __gcd(geven, arr[i]);
    }
    for(int i = 1; i<n; i+=2){
        godd = __gcd(godd, arr[i]);
    }
    bool pos = true;
    for(int i = 0; i<n; i+=2){
        if(arr[i]%godd == 0){
            pos = false;
            break;
        }
    }
    if(!pos){
        pos = true;
        for(int i = 1; i<n; i+=2){
            if(arr[i]%geven == 0){
                pos = false;
                break;
            }
        }
        if(pos){
            cout << geven << nl;
        }
        else{
            cout << 0 << endl;
        }
    }
    else{
        cout << godd << nl;
    }

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