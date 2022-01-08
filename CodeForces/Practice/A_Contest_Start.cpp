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
        ll n, x, t;
        cin >> n >> x >> t;
        cout << max((ll)0, n - t/x)*(t/x) + min(n-1, t/x-1)*min(n, t/x)/2 << endl;
    }
    return 0;
}