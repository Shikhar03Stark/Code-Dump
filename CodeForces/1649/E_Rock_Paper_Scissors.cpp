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

vector<pair<int,int>> nowin;
vector<pair<int,int>> state;
int N = 9;

void simstate(vector<int> a, vector<int> b, int idx, int win, int &mi, int &ma){
    ll suma = a[0]+a[1]+a[2], sumb = b[0]+b[1]+b[2];
    if(suma==0 && sumb==0){
        mi = min(mi, win);
        ma = max(ma, win);
        return;
    }
    if(idx>=N) return;
    //don't take state
    simstate(a, b, idx+1, win, mi, ma);
    //take
    for(auto& e: nowin){
        if(e == state[idx]){
            //no winning
            int mv = min(a[state[idx].first], b[state[idx].second]);
            a[state[idx].first] -= mv;
            b[state[idx].second] -= mv;

            simstate(a, b, idx+1, win, mi, ma);
            return;
        }
    }

    //results in winning
    int mv = min(a[state[idx].first], b[state[idx].second]);
    a[state[idx].first] -= mv;
    b[state[idx].second] -= mv;

    simstate(a, b, idx+1, win+mv, mi, ma);
}

void solve(){
    int n;
    cin >> n;
    vector<int> a(3), b(3);
    for(auto& e: a){
        cin >> e;
    }
    for(auto& e: b){
        cin >> e;
    }
    int ma = min(a[0],b[1]) + min(a[1], b[2]) + min(a[2], b[3]);

    nowin = {
        {0,0},
        {0,1},
        {2,2},
        {2,1},
        {1,1},
        {1,0}
    };
    for(int i = 0; i<6; i++){
        int mv = min(a[nowin[i].first], b[nowin[i].second]);
        a[nowin[i].first] -= mv;
        b[nowin[i].second] -= mv;
    }
    int mi = min(a[0],b[1]) + min(a[1], b[2]) + min(a[2], b[3]);
    cout << ma << " " << mi << nl;
    return;
}

int main(){
    FASTIO
    pre();
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}