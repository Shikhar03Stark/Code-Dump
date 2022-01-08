#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

int main(){
    FASTIO
    ll a,b,c;
    cin >> a >> b >> c;
    cout << (ll)(ceil((a+0.0)/c)*ceil((b+0.0)/c)) << endl;
    return 0;
}