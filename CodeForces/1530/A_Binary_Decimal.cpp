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
        ll n;
        cin >> n;
        if(n == 0){
            cout << 1 << endl;
            continue;
        }
        ll big = 1;
        while(n > 0){
            big = max(n%10, big);
            n /= 10;
        }

        cout << big << endl;
    }
    return 0;
}