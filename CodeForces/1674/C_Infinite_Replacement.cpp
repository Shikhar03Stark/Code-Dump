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
    string s;
    string t;
    cin >> s >> t;
    int sz = s.size(), tz = t.size();
    // cerr << (1ULL<<50) << nl;
    if(tz == 1){
        if(t[0] == 'a'){
            cout << 1 << nl;
        }
        else{
            ull ans = (1ULL<<sz);
            cout << ans << nl;
            return;
        }
    }
    else{
        bool hasa = false;
        for(int i = 0; i<tz; i++){
            if(t[i]=='a'){
                hasa = true;
                break;
            }
        }
        if(hasa){
            cout << -1 << nl;
        }
        else{
            ull ans = (1ULL<<sz);
            cout << ans << nl;
            return;
        }
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