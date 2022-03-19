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

int maxlen(int zero, int one, int any){
    int d = one - zero;
    if(d<0){
        int r = min(any, zero-one);
        any -= r;
        one += r;
    }
    else if(d>0){
        int r = min(any, one-zero);
        any -= r;
        zero += r;
    }
    return min(zero, one) + any/2;
}

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    // int n = s.size();
    int zero = 0, one = 0, any = 0;
    int ans = 0;
    for(int i = 0; i<n; i++){
        if(s[i] == '0') zero++;
        if(s[i] == '1') one++;
        if(s[i] == '?') any++;
        ans = max(ans, 2*maxlen(zero, one, any));
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