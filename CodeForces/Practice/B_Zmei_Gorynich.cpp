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
    int n, x;
    cin >> n >> x;
    vector<int> d(n), h(n);
    int minc = 0;
    int slash = 0;
    for(int i = 0; i<n; i++){
        cin >> d[i] >> h[i];
        minc = max(minc, d[i]);
        slash = max(slash, d[i]-h[i]);
    }

    if(x <= minc){
        cout << 1 << nl;
        return;
    }
    else{
        if(slash <= 0){
            cout << -1 << nl;
        }
        else{
            int k = ceil((x-minc+0.0)/slash);
            x -= k*slash;
            if(x > 0) k++;
            cout << k << nl;
        }
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