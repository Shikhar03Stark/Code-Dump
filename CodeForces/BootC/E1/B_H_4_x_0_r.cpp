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

char hack(char c){
    if(c == 'a') return '4';
    if(c == 'i') return '1';
    if(c == 'e') return '3';
    if(c == 'o') return '0';
    if(c == 's') return '5';
    return c;
}

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    for(int i = 0; i<n; i++){
        s[i] = hack(s[i]);
    }
    cout << s << nl;
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