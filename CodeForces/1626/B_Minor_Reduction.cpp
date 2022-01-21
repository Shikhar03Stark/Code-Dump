// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    if(n==1){
        cout << s << nl;
        return;
    }
    for(int i = n-2; i>=0; i--){
        if((s[i]-'0' + s[i+1]-'0')>=10){
            cout << s.substr(0,i) + to_string(s[i]-'0' + s[i+1]-'0') + s.substr(i+2) << nl;
            return;
        }
    }
    cout << to_string(s[0]-'0' + s[1]-'0')+s.substr(2) << nl;
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