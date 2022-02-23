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
    map<char,bool> key;
    for(auto e: s){
        if(e == 'r' || e == 'g' || e == 'b'){
            key[e] = true;
        }
        else{
            if(!key[e-'A'+'a']){
                cout << "NO" << nl;
                return;
            }
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