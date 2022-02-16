// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;
vector<ll> p2;
int sz;
void pre(){
    ll x = 1;
    while(x<=1e16){
        p2.push_back(x);
        x *= 2;
    }
    sz = p2.size();
    // cerr << sz << nl;
    return;
}

void solve(){
    ll num;
    cin >> num;
    int ans = 32;
    for(auto p: p2){
        string n = to_string(num);
        string ps = to_string(p);
        int cnt = 0;
        int i = 0, j = 0;
        while(i<n.size() && j<ps.size()){
            if(n[i] == ps[j]){
                i++;
                j++;
            }
            else{
                i++;
                cnt++;
            }
        }
        cnt += n.size()-i + ps.size()-j;
        ans = min(ans, cnt);
    }
    cout << ans << nl;
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