// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(n>=3){
        cout << "NO" << nl;
    }
    else{
        if(n==2){
            if(s[0] == s[1]){
                cout << "NO" << nl;
                return;
            }
        }
        cout << "YES" << nl;
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