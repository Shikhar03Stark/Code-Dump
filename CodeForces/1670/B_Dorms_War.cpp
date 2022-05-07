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

bool isspl(char c, vector<char> &sp){
    for(auto& e: sp){
        if(e == c) return true;
    }
    return false;
}

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int k;
    cin >> k;
    vector<char> spl(k);
    for(auto& e: spl){
        cin >> e;
    }
    vector<int> ans(n, 0);
    bool allsp = true;
    int last = 0;
    for(int i = 0; i<n; i++){
        if(i){
            if(isspl(s[i], spl)){
                ans[i] = i-last;
                last = i;
            }
        }
    }
    cout << *max_element(ans.begin(), ans.end()) << nl;
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