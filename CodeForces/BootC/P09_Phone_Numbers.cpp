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
    string s;
    cin >> s;
    int c8 = 0;
    for(int i = 0; i<n; i++){
        if(s[i] == '8') c8++;
    }
    int rest = n-c8;
    int ph = 0;
    while(c8>0){
        if(rest>=10 && c8 > 0){
            ph++;
            rest -= 10;
            c8--;
        }
        else{
            int req = 10-rest;
            if(req>c8){
                break;
            }
            else{
                rest += req;
                c8 -= req;
            }
        }
    }

    cout << ph << nl;
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