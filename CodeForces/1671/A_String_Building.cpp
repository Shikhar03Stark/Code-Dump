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
    if(n == 1) {
        cout << "NO" << nl;
        return;
    }
    int i = 0;
    while(i<n){
        int j = i;
        while(j+1<n && s[j+1] == s[j]){
            j++;
        }
        if(j-i+1 <= 1){
            cout << "NO" << nl;
            return;
        }
        i = j+1;
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