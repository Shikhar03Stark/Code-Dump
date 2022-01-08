// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

int solve(){
    string s;
    cin >> s;
    int n = s.size();
    if(n%2==1){
        cout << "NO" << nl;
        return 0;
    }
    bool ans = true;
    for(int i = 0, j=n/2; i<n/2 && j<n; i++, j++){
        if(s[i] != s[j]){
            ans = false;
            break;
        }
    }
    cout << (ans?"YES":"NO") << nl;
    return 0;
}

int main(){
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}