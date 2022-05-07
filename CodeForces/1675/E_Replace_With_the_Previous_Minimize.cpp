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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if(k>=25){
        for(int i = 0; i<n; i++){
            cout << 'a';
        }
        cout << nl;
    }
    else{
        for(int i = 0; i<n && k>0; i++){
            if(s[i] == 'a') continue;
            int j = i;
            int upper;
            int maxi = -1;
            for(;j<n; j++){
                if(s[j] >= s[i] && s[j]-'a' <= k){
                    maxi = max(maxi, s[j]-'a');
                }
            }
            if(maxi==-1){
                s[i] = max()
            }
            else{
                for(int j = i+1; j<n; j++){
                    if(s[j] <= maxi+'a'){
                        s[j] == 'a';
                    }
                }
            }

        }
        cout << s << nl;
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