// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    bool p = true;
    for(int i = 0; i<n/2; i++){
        if(s[i] != s[n-i-1]){
            p = false;
            break;
        }
    }
    if(p){
        cout << 1 << nl;
    }
    else{
        if(k==0){
            cout << 1 << nl;
        }
        else{
            cout << 2 << nl;
        }
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