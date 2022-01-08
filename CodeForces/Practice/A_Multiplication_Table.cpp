#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

int main(){
    ll n, x;
    cin >> n >> x;
    ll f = 0;
    for(ll i = 1; i<=n; i++){
        if(x%i == 0 && x/i<=n) f++;
    }
    cout << f << endl;
    return 0;
}