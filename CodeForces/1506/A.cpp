#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n, m, x;
        cin >> n >> m >> x;
        x--;
        int i = x%n;
        int j = x/n;

        cout << 1 + (i*m + j) << endl;

    }
    return 0;
}