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
        ll a,b;
        cin >> a >> b;
        if(a == b){
            cout << 0 << ' ' << 0 << endl;
        }
        else{
            cout << abs(a-b) << " ";
            if(a<b) swap(a,b);
            ll g = a-b;
            cout << min(b%g, g - a%g) << endl;
        }
    }
    return 0;
}