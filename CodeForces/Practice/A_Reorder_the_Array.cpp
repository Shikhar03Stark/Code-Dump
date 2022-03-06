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
    multiset<int> S;
    for(auto& e: arr){
        cin >> e;
        S.insert(e);
    }
    int cnt = 0;
    for(int i = 0; i<n; i++){
        auto it = S.upper_bound(arr[i]);
        if(it != S.end()){
            cnt++;
            S.erase(it);
        }
    }
    cout << cnt << nl;

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