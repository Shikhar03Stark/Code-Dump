#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

ll extended_gcd(ll a, ll b, ll &x, ll &y){
    if(a<b) return extended_gcd(b, a, y, x);
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll g = extended_gcd(b, a%b, x1, y1);
    x = y1;
    y = x1 - (a/b)*y1;
    return g;
}

int main(){
    vector<vector<ll>> tests = {
        {16, 24, 0, 0},
        {17, 99, 0, 0},
        {5, 12, 0, 0}
    };
    for(auto& test:tests){
        cout << "For: " << test[0] << ", " << test[1] << endl;
        cout << "gcd: " << extended_gcd(test[0], test[1], test[2], test[3]) << endl;
        cout << test[2] << ", " << test[3] << endl;
    }
    return 0;
}