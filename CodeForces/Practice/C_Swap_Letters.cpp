// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

int solve(){
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    vector<int> ab, ba;
    for(int i = 0; i<n; i++){
        if(s[i] != t[i]){
            if(s[i] == 'a'){
                ab.push_back(i+1);
            }
            else{
                ba.push_back(i+1);
            }
        }
    }
    int sab = ab.size(), sba = ba.size();
    if((sab+sba)%2 == 1){
        cout << -1 << nl;
    }
    else{
        if(sab%2==0){
            cout << (sab+sba)/2 << nl;
            for(int i = 0; i<sab; i+=2){
                cout << ab[i] << ' ' << ab[i+1] << nl;
            }
            for(int i = 0; i<sba; i+=2){
                cout << ba[i] << ' ' << ba[i+1] << nl;
            }
        }
        else{
            cout << 1+(sab+sba)/2 << nl;
            for(int i = 1; i<sab; i+=2){
                cout << ab[i] << ' ' << ab[i+1] << nl;
            }
            for(int i = 1; i<sba; i+=2){
                cout << ba[i] << ' ' << ba[i+1] << nl;
            }
            cout << ab[0] << ' ' << ab[0] << nl;
            cout << ab[0] << ' ' << ba[0] << nl;
        }
    }

    return 0;
}

int main(){
    FASTIO
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}