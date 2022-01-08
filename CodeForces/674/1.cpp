#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n, x;
        cin >> n >> x;

        n = n - 2;
        if(n <= 0){
            cout << 1 << endl;
            continue;
        }

        ll floor = 1;
        floor += ceil(n*1.0/x);

        cout << floor << endl;
    }
    return 0;
}