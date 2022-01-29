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
    cout << n/2 + 1 << nl;
    ll pr = 1, pc = 1;
    cout << 1 << " " << 1 << nl;
    for(int i = 2; i<=n; i++){
        if(i%2==0){
            cout << (pr=pr) << ' ' << (pc=pc+1) << nl;
        }
        else{
            cout << (pr=pr+1) << " " << (pc=pc) << nl;
        }
    }
    return;
}

int main(){
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}