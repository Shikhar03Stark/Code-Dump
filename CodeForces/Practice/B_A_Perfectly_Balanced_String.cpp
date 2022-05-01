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
    set<char> uniq(s.begin(), s.end());
    int uq = uniq.size();
    set<char> run;
    for(int i = 0; i<uq; i++){
        if(run.find(s[i]) != run.end()){
            cout << "NO" << nl;
            return;
        }
        run.insert(s[i]);
    }
    for(int i = 0; i+uq<n; i++){
        if(s[i] != s[i+uq]){
            cout << "NO" << nl;
            return;
        }
    }
    cout << "YES" << nl;
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