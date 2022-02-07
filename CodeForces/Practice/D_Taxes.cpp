// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

const int MAXN = 6e4;

vector<bool> p(MAXN+1, true);
vector<ll> primes;
int psz;
void pre(){
    for(ll i = 2; i<=MAXN; i++){
        if(p[i]){
            primes.push_back(i);
            for(ll j = i*(ll)i; j<=MAXN; j += i){
                p[j] = false;
            }
        }
    }
    psz = primes.size();
}

bool isprime(ll n){
    int i = 0;
    while(i<psz && primes[i]*primes[i]<=n){
        if(n%primes[i++] == 0){
            return false;
        }
    }
    return true;
}

ll ans(ll n){
    if(n == 2) {cerr << 2 << " "; return 1; }
    if(isprime(n)) { cerr << n << " "; return 1; }
    for(ll i = n-2; i>=2; i--){
        if(isprime(i)){
            cerr << i << " ";
            return 1+ans(n-i);
        }
    }
    return 1;
}

void solve(){
    ll n;
    cin >> n;
    if(isprime(n)){
        cout << 1 << nl;
    }
    else if(n%2==0){
        cout << 2 << nl;
    }
    else{
        if(n>2 && isprime(n-2)){
            cout << 2 << nl;
        }
        else{
            cout << 3 << nl;
        }
    }
    return;
}

int main(){
    pre();
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}