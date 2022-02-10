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
    stack<char> S;
    for(int i = 0; i<n; i++){
        if(S.empty()){
            S.push(s[i]);
        }
        else{
            if(S.top() == s[i]){
                S.pop();
            }
            else{
                S.push(s[i]);
            }
        }
    }
    if(S.size()>0){
        cout << "No" << nl;
    }
    else{
        cout << "Yes" << nl;
    }
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