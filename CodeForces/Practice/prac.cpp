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

void cnt(vector<int> &s, int si, int idx, int open, int close, int &ans, int maxn){
    if(open<close) return;
    if(open+close>maxn) return;
    if(idx == maxn) { ans++; return;}
    if(s[si] == idx){
        //op
        cnt(s, si+1, idx+1, open+1, close, ans, maxn);
    }
    else{
        cnt(s, si, idx+1, open+1, close, ans, maxn);
        if(open>close)
            cnt(s, si, idx+1, open, close+1, ans, maxn);
    }
}

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(k);
    for(auto& e: arr){
        cin >> e;
    }
    int ans = 0;
    cnt(arr, 0, 1, 0, 0, ans, 2*n);
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