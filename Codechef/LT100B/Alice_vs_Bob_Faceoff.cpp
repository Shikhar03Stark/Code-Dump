#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

int solve(ll n){
    if(n==0) return 0;
    if(n%2 == 1) return !solve(n-1);
    if(n%4 != 0) return !solve(n/2);

    return 1;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin >> n;
        if(n == 1){
            cout << "Alice" << endl;
            continue;
        }
        cout << (solve(n)?"Alice":"Bob") << endl;
    }
    return 0;
}