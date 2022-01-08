#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long unsigned int

using namespace std;

int main(){
    FASTIO
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin >> n;
        map<ll,ll> h;
        for(ll i = 1; i<=n; i++){
            h[i] = i;
        }
        if( (n&(n-1)) == 0){
            cout << -1 << endl;
        }
        else{
            for(ll i = 1; i<=n; i++){
                if( (i&(i-1)) == 0){
                    swap(h[i], h[i+1]);
                }
            }

            for(ll i = 1; i<=n; i++){
                cout << h[i] << " ";
            }
            cout << endl;
        }

        
    }
    return 0;
}