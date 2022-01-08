#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

int solve(){
    ll n;
    cin >> n;
    if(n%2 == 0){
        cout << 0 << endl;
    }
    else{
        ll t = n;
        bool hasEven = false;
        while(t>9){
            t /= 10;
            if(!hasEven)
                hasEven = (t%2==0)?true:false;
        }
        if(t%2==0){
            cout << 1 << endl;
            return 0;
        }
        if(hasEven){
            cout << 2 << endl;
        }
        else{
            cout << -1 << endl;
        }
    }
    return 0;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}