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
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for(auto& e: arr){
        cin >> e;
    }
    map<int,int> h;
    for(int i = 0; i<n; i++){
        int rem = x-arr[i];
        if(h.count(rem) > 0){
            cout << "YES" << nl;
            return;
        }
        h[arr[i]] = i;
    }
    cout << "NO" << nl;
    return;
}

int main(){
    FASTIO
    pre();
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}