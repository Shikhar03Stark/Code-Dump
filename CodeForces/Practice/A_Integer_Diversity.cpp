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
    map<int,int> h;
    for(auto& e: arr){
        cin >> e;
        h[abs(e)]++;
    }

    int ans = 0;
    for(auto& e: h){
        if(e.first != 0)
            ans += (e.second>=2?2:1);
        if(e.first == 0)
            ans += 1;
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