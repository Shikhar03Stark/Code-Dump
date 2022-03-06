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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int op = 0, cl = 0;
    for(int i = 0; i<n; i++){
        if(s[i]=='(') op++;
        else cl++;
    }
    if(op!=cl){
        cout << -1 << nl;
        return ;
    }
    op = 0, cl = 0;
    int last = -1;
    for(int i = 0; i<n; i++){
        
    }
    cout << ans << nl;
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