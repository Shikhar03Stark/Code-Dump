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
        ull p, a, b, c, x, y;
        cin >> p >> a >> b >> c >> x >> y;
        int ans = max(p/(b+a*x),p/(c+a*y));
        cout << ans << endl;
    }
    return 0;
}