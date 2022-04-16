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
    string s1, s2, p;
    cin >> s1;
    cin >> s2;
    cin >> p;
    string s = s1+s2;
    sort(s.begin(), s.end());
    sort(p.begin(), p.end());

    if(s.size() != p.size()){
        cout << "NO" << nl;
        return;
    }

    for(int i = 0; i<s.size(); i++){
        if(s[i] != p[i]){
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
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}