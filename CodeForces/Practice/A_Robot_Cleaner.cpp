// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

int solve(){
    int n,m, x0, y0, x1, y1;
    cin >> n >> m >> x0 >> y0 >> x1 >> y1;
    int time = INT_MAX;
    if(x1>=x0){
        time = min(time, x1-x0);
    }
    else{
        time = min(time, 2*n-x1-x0);
    }
    if(y1>=y0){
        time = min(time, y1-y0);
    }
    else{
        time = min(time, 2*m-y1-y0);
    }
    cout << time << nl;
    return 0;
}

int main(){
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}