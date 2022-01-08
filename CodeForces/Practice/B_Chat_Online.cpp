// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

int solve(){
    int p, q, l, r;
    cin >> p >> q >> l >> r;
    bitset<1001> onlineZ, onlineX;
    //vector<bool>()
    for(int i = 0; i<p; i++){
        int a, b;
        cin >> a >> b;
        for(int j = a; j<=b; j++){
            onlineZ[j] = 1;
        }
    }

    for(int i = 0; i<q; i++){
        int a, b;
        cin >> a >> b;
        for(int j = a; j<=b; j++){
            onlineX[j] = 1;
        }
    }

    int cnt = 0;
    for(int i = l; i<=r; i++){
        cerr << (onlineX<<i) << nl;
        if((onlineZ & (onlineX<<i)).any()){
            //overlap
            cnt++;
        }
    }

    cout << cnt << nl;

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