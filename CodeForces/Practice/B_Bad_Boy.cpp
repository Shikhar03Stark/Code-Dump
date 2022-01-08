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
        ll n, m, x, y;
        cin >> n >> m >> x >> y;
        ll x1, y1, x2, y2;
        x1=1; y1=1; x2=m; y2=n;
        ll dist = abs(x-x1) + abs(y-y1) + abs(x-x2) + abs(y-y2);
        x1=m;y1=1;x2=1;y=n;
        if(dist < abs(x-x1) + abs(y-y1) + abs(x-x2) + abs(y-y2)){
            cout << y1 << ' ' << x1 << ' ' << y2 << ' ' << x2 << endl;
            continue;
        }
        cout << 1 << ' ' << 1 << ' ' << n << ' ' << m << endl;
    }
    return 0;
}