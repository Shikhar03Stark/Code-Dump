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
    vector<pair<ll,ll>> pts(3);
    for(int i = 0; i<3; i++){
        cin >> pts[i].first >> pts[i].second;
    }
    //cerr << "3L done" << nl;
    for(int i = 0; i<3; i++){
        for(int j = i+1; j<3; j++){
            if(pts[i].second == pts[j].second){
                int k = 3-i-j;
                if(pts[k].second < pts[i].second){
                    cout << abs(pts[i].first - pts[j].first) << nl;
                    return;
                }
            }
        }
    }
    cout << 0.0 << nl;
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