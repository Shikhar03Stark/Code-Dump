#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

int solve(){
    ll a, b;
    cin >> a >> b;
    ll ans = 0;
    while((a+b)>=4 && a>0 && b>0){
        if(a>b){
            swap(a,b);
            continue;
        }
        ll del = b-a;
        if(del == 0){
            ans += (a/2);
            a=0;
        }
        else if(del == 1){
            ans += (a/2);
            a=2;
            b=1;
        }
        else{
            ll x = (b-a)/2;
            if(a-x>=0 && b-3*x>=0){
                ans += x;
                a -= x;
                b -= 3*x;
            }
            else{
                ans += a;
                a = 0;
            }
        }
    }
    cout << ans << endl;
    return 0;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}