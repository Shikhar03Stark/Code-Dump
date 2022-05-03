// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

vector<string> d;

void pre(){
    for(char c = 'a'; c<='z'; c++){
        for(char x = 'a'; x<='z'; x++){
            if(c!=x){
                string s;
                s.push_back(c);
                s.push_back(x);
                d.push_back(s);
            }
        }
    }
    return;
}

void solve(){
    string s;
    cin >> s;
    for(int i = 0; i<d.size(); i++){
        if(d[i] == s){
            cout << i+1 << nl;
            return;
        }
    }
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