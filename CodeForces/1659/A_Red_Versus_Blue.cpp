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
    int n, r, b;
    cin >> n >> r >> b;
    int p = r/(b+1);
    int q = r%(b+1);
    for(int i = 0; i<q; i++) cout << string(p+1, 'R') << 'B';
    for(int i = q; i<b; i++) cout << string(p, 'R') << "B";
    cout << string(p, 'R') << nl;
    // cout << nl;
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