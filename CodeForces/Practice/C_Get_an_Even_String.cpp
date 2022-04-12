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

int sz = 26;

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    int len = 0;
    vector<bool> p(sz, false);
    for(int i = 0; i<n; i++){
        if(p[s[i]-'a']){
            len += 2;
            for(int i = 0; i<sz; i++) p[i] = false;
        }
        else{
            p[s[i]-'a'] = true;
        }
    }
    cout << n - len << nl;
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