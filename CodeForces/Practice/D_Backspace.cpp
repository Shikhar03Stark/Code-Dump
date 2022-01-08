// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

void solve(){
    string s, t;
    cin >> s >> t;
    int sn = s.size(), tn = t.size();
    int i = sn-1, j = tn-1;
    bool found = false;
    for(;i>=0 && j>=0;){
        if(s[i] == t[j]){
            i--;
            j--;
        }
        else{
            i -= 2;
        }
        if(j<0) found = true;
    }

    cout << (found?"YES":"NO") << nl;
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