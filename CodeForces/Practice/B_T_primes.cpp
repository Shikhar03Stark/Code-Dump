#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

set<ll> prime;

bool isPrime(ll n){
    for(ll x = 2; x*x<= n; x++){
        if(n%x==0){
            return false;
        }
    }

    return true;
}

void solve(){
    prime.insert(4);
    for(ll i = 3; i<=1e6; i++){
        if(isPrime(i)){
            prime.insert(i*i);
        }
    }
}

int main(){
    solve();
    int n;
    cin >> n;
    vector<ll> arr(n);
    for(auto&e:arr){
        cin >> e;
    }
    for(auto &e: arr){
        if(prime.find(e) == prime.end()) cout << "NO" << endl; else cout << "YES" << endl;
    }
    return 0;
}