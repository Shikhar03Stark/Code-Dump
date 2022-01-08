#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll l, r, m;
        cin >> l >> r >> m;
        ll nr = (m+r-l);
        ll a,b,c;
        for(a = l; a<=r; a++){
            ll n = nr/a;
            if(n<=0) continue;
            ll x = m - a*n;
            if(x>=0){
                b = l+x;
                c = l;
            }
            else{
                c = l-x;
                b = l;
            }
            if(b>=l&&b<=r && c>=l && c<=r){
                break;
            }
        }
        cout << a << " " << b << " " << c << endl;
    }
    return 0;
}