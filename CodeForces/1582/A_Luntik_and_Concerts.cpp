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
        ll a, b, c;
        cin >> a >> b >> c;
        ll tot = a + 2*b + 3*c;
        cout << (tot&1) << endl;
    }
    return 0;
}