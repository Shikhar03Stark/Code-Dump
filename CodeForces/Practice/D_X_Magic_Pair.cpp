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
        ll a, b, x;
        cin >> a >> b >> x;
        queue<pair<ll,ll>> Q;
        Q.push({a,b});
        set<pair<ll,ll>> vis;
        bool found = false;
        if(a == x || b == x){
            found = true;
        }
        else{
            //cerr << a << " " << b << " " << __gcd(a,b) << endl;
            if(__gcd(a,b) > 1){
                if(x%__gcd(a,b) == 0|| __gcd(a,b)%x == 0){
                    if(x <= min(a,b))
                    found = true;
                }
                else{
                    found = false;
                }
            }
            else{
                found = true;
            }
        }
        if(found){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}