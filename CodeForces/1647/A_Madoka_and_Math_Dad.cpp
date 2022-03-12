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
    int n;
    cin >> n;
    if(n%3==2){
        for(int i = 0; i<n/3; i++){
            cout << 21;
        }
        cout << 2 << nl;
    }
    else if(n%3==1){
        for(int i = 0; i<n/3; i++){
            cout << 12;
        }
        cout << 1 << nl;
    }
    else{
        for(int i = 0; i<n/3; i++){
            cout << 21;
        }
        cout << nl;
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