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

bool remove2palin(string &s, int idx){
    if(s[idx] == s[idx+1]){
        int val = (s[idx]-'a'+idx+1)*(s[idx+1]-'a'+1) % 26;
        s[idx] = val+'a';
        return true;
    }
    return false;
}

int remove3palin(string &s, int idx){
    if(s[idx] == s[idx+2] || s[idx+2] == s[idx+1]){
        if(s[idx] == s[idx+2]){
            int val = (s[idx]-'a'+idx+1)*(s[idx+2]-'a'+1) % 26;
            s[idx] = val+'a';
            // return true;
            return 1;
        }
        if(s[idx+1] == s[idx+2]){
            int val = (s[idx+1]-'a'+idx+1)*(s[idx+2]-'a'+1) % 26;
            s[idx+2] = val+'a';
            return 2;
        }
        // return true;
    }
    return 0;
}

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    int ans = 0;
    vector<bool> mark(n, false);
    for(int i = 1; i<n; i++){
        if(i>1){
            if(s[i] == s[i-2] && !mark[i-2]) mark[i] = true;
            if(s[i] == s[i-1] && !mark[i-1]) mark[i] = true;
        }
        else{
            if(s[i] == s[i-1]) mark[i] = true;
        }
    }
    // for(auto  e: mark){
    //     cerr << e;
    // }
    // cerr << nl;
    int sum = accumulate(mark.begin(), mark.end(), 0);
    // cerr << s << nl;
    cout << sum << nl;
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