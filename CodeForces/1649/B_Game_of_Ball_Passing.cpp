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
    vector<int> arr(n);
    ll sum = 0;
    for(auto& e: arr){
        cin >> e;
        sum += e;
    }
    if(sum==0){
        cout << 0 << nl;
        return;
    }
    ll ma = *max_element(arr.begin(), arr.end());
    if(sum-ma>=ma){
        cout << 1 << nl;
        return;
    }
    else{
        cout << (2*ma-sum) << nl;
        return;
    }

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