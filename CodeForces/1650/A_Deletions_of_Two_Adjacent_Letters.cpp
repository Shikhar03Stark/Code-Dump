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
    char c;
    cin >> c;
    int n = s.size();
    for(int i = 0; i<n; i++){
        if(s[i] == c){
            if(i%2==0 && (n-i-1)%2==0){
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << nl;
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