// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

void lowercase(string &s){
    int n = s.size();
    for(int i = 0; i<n; i++){
        if(s[i]>='A' && s[i]<='Z'){
            s[i] = 'a' + s[i] - 'A';
        }
    }
}

int solve(){
    string s, t;
    cin >> s >> t;
    lowercase(s);
    lowercase(t);
    if(s<t){
        cout << -1 << nl;
    }
    else if(s>t){
        cout << 1 << nl;
    }
    else{
        cout << 0 << nl;
    }
    return 0;
}

int main(){
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}