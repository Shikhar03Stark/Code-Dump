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
    bool haszeros = false;
    for(int i = 0; i<n; i++){
        if(s[i] == '0'){
            haszeros = true;
            break;
        }
    }
    if(!haszeros){
        cout << 1 << " " << n-1 << " " << 2 << " " << n << nl;
        return;
    }
    for(int i = 0; i<n; i++){
        if(s[i] == '0'){
            if(i<n/2){
                cout << i+1 << " " << n << " " << i+2 << " " << n << nl;
                return;
            }
            else{
                cout << 1 << " " << i+1 << " " << 1 << " " << i << nl;
                return;
            }
        }
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