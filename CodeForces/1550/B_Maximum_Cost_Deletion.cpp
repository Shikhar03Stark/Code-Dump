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
        int n, a, b;
        cin >> n >> a >> b;
        string s;
        cin >> s;
        ll ans = a*n;
        if(b > 0){
            ans += b*n;
            cout << ans << endl;
        }
        else{
            ll k = 1;
            for(int i = 1; i<n; i++){
                if(s[i] != s[i-1])
                    k++;
            }
            k /= 2;
            ans += max(b*(1+k), (ll)b*n);
            cout << ans << endl;
        }
    }
    return 0;
}