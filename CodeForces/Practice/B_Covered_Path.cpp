// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

int solve(){
    int v1, v2, t, d;
    cin >> v1 >> v2 >> t >> d;
    int sum = 0;
    for(int i = 0; i<t; i++){
        sum += min(v1+d*i, v2 + d*(t-i-1));
    }
    cout << sum << nl;
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