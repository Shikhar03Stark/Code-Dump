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
    cin >> s;
    int n = s.size();
    int ans = s.size();
    for(auto m: {"00", "50", "25", "75"}){
        char f = m[0], p = m[1];
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                if(s[i]==f && s[j]==p){
                    ans = min(ans, n-i-2);
                }
            }
        }
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