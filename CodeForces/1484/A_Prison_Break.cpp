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
        int a, b;
        cin >> a >> b;
        int ans = min(a*(b-1) + a, b*(a-1) + b);
        cout << ans << endl;
    }
    return 0;
}