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
        ll u, v;
        cin >> u >> v;
        ll x = -u*u;
        ll y = v*v;
        cout << x << " " << y << endl;
    }
    return 0;
}