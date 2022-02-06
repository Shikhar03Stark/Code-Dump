// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

bool possible(ll x, ll b, ll s, ll c, ll nb, ll ns, ll nc, ll pb, ll ps, ll pc, ll r){
    ll money = pb*(max(0LL, b*x-nb)) + ps*(max(0LL, s*x - ns)) + pc*(max(0LL, c*x-nc));
    cerr << x << ":" << money << nl;
    return money<=r;
}

void solve(){
    string st;
    cin >> st;
    ll nb, ns, nc;
    cin >> nb >> ns >> nc;
    ll pb, ps, pc;
    cin >> pb >> ps >> pc;
    ll r;
    cin >> r;
    ll b = 0, s = 0, c = 0;
    for(auto& e: st){
        if(e == 'B') b++;
        if(e == 'S') s++;
        if(e == 'C') c++;
    }
    cerr << b << " " << s << " " << c << nl;
    ll low = 0, high = 1e12 + max({nb, ns, nc}) + 10, mid = 0;
    while(low<=high){
        mid = low+(high-low)/2;
        if(possible(mid, b, s, c, nb, ns, nc, pb, ps, pc, r)){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }

    cout << high << nl;

    return;
}

int main(){
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}