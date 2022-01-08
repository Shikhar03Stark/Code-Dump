// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    double ans = (0.0+n-k*k+k)/(k);
    if(ceil(ans) == floor(ans)){
        if((int)floor(ans)%2==1){
            cout << "YES" << nl;
        }
        else{
            cout << "NO" << nl;
        }
    }
    else{
        cout << "NO" << nl;
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