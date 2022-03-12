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
    ll n, m;
    cin >> n >> m;
    vector<tuple<ll, ll, ll>> pts(m);
    int idx = 1;
    for(auto& p: pts){
        cin >> get<0>(p) >> get<1>(p);
        get<2>(p) = idx++;
    }
    sort(pts.begin(), pts.end());
    priority_queue<tuple<ll,ll, ll>> pq;
    ll sum = 0;
    ll ans = INT_MAX;
    for(int i = 0; i<m; i++){
        bool ins = false;
        if(pq.size()<2*n){
            pq.push({get<1>(pts[i]), get<0>(pts[i]), get<2>(pts[i])});
            sum += get<1>(pts[i]);
            ins = true;
        }

        if(pq.size()==2*n){
            if(get<1>(pts[i]) < get<0>(pq.top()) && !ins){
                sum += get<1>(pts[i]) - get<0>(pq.top());
                pq.pop();
                pq.push({get<1>(pts[i]), get<0>(pts[i]), get<2>(pts[i])});
            }
            ans = min(ans, sum);
        }
    }
    vector<tuple<ll,ll,ll>> seg;
    while(!pq.empty()){
        seg.push_back({get<1>(pq.top()), get<0>(pq.top()), get<2>(pq.top())});
        pq.pop();
    }
    sort(seg.begin(), seg.end());
    cout << ans << nl;
    for(int i = 0; i<n; i++){
        cout << get<2>(seg[i]) << " " << get<2>(seg[2*n-i-1]) << nl;
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