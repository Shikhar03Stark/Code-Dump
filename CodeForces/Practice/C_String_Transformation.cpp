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
    string ans;
    int i = 0;
    char match = 'a';
    while(i<n && match<='z'){
        if(s[i] <= match){
            s[i] = match;
            match++;
        }
        i++;
    }
    if(match > 'z'){
        cout << s << nl;
    }
    else{
        cout << -1 << nl;
    }
    // if(ans.size() < 26){
    //     cout << -1 << nl;
    // }
    // else{
    //     cout << s << nl;
    // }
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