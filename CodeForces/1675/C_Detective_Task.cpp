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
    if(n==1){
        cout << 1 << nl;
    }
    else{
        int j = n-1;
        for(int i = 0; i<n; i++){
            if(s[i] == '0'){
                j = i;
                break;
            }
        }
        int ans = 0;
        for(int i = j; i>=0; i--){
            ans++;
            if(s[i] == '1'){
                break;
            }
        }
        cout << ans << nl;
        
    }
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