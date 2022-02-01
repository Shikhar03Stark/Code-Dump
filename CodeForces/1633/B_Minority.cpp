// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

void solve(){
    string s;
    cin >> s;
    vector<int> cnt(2,0);
    for(auto c: s){
        cnt[c-'0']++;
    }
    if(cnt[0] == cnt[1]){
        if(s[0]-'0' == 0){
            cnt[0]--;
        }
        else{
            cnt[1]--;
        }
        cout << min(cnt[0], cnt[1]) << nl;
    }
    else{
        cout << min(cnt[0], cnt[1]) << nl;
    }
    return;
}

int main(){
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}