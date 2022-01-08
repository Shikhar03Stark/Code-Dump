#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

int solve(){
    ll n;
    cin >> n;
    ll t=n;
    ll ans = 1;
    while(n%2==1){
        ans = (ans<<1);
        n = (n>>1);
    }
    cout << ans << endl;

    ll c=1,f=0;
    while(f==0){
        if((c^t)==(c+t)){
            f=1;
            cerr<<c<<endl;
            return 0;
        }
        c<<=1;
    }
    cerr<<0<<endl;
    return 0;
}

int main(){
    FASTIO
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}