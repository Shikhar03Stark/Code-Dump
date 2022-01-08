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
        ll x, y;
        cin >> x >> y;
        if((x+y)%2 == 0){
            ll D = x+y;
            if(x>=y){
                cout << D/2 << " " << 0 << endl;
            }
            else{
                cout << x << " " << y-D/2 << endl;
            }
        }
        else{
            cout << -1 << " " << -1 << endl;
        }
    }
    return 0;
}