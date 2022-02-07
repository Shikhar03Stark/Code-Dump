// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    if(m==1){
        cout << "YES" << nl;
        for(int i =1; i<=n; i++){
            cout << i << nl;
        }
    }
    else{
        if(n&1==1){
            cout << "NO" << nl;
        }
        else{
            cout << "YES" << nl;
            for(int i = 1; i<=n; i++){
                for(int j = i; j<=m*n; j+=n){
                    cout << j << " ";
                }
                cout << nl;
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