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
    if(n >= 1900){
        cout << "Division 1" << nl;
    }
    else if(n >= 1600 && n < 1900){
        cout << "Division 2" << nl;
    }
    else if(n >= 1400 && n < 1600){
        cout << "Division 3" << nl;
    }
    else{
        cout << "Division 4" << nl;
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