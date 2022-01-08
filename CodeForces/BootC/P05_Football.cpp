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
    int cnt = 1;
    bool dang = false;
    int n = s.size();
    for(int i = 1; i<n; i++){
        if(s[i] != s[i-1]){
            cnt = 1;
        }
        else{
            cnt++;
        }
        if(cnt>=7){
            dang = true;
            break;
        }
    }
    cout << (dang?"YES":"NO") << nl;
    return 0;
}

int main(){
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}