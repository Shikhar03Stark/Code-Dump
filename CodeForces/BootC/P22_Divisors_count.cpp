// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

vector<int> primes;
vector<bool> p(10001, true);
int sz;
void pre(){
    int n = 10000;
    for(int i = 2; i<=n; i++){
        if(p[i]){
            for(int j = i*i; j<=n; j+=i){
                p[i] = false;
            }
        }
    }
    for(int i = 2; i<=n; i++){
        if(p[i])
            primes.push_back(i);
    }
    sz = primes.size();
}

ll factors(int n){
    if(n==1) return 1;
    ll cnt = 0;
    int k = 0;
    for(int i = 2; i*i<=n; i++){
        while(n%i==0){
            cnt++;
            n /= i;
        }
    }

    if(n>1){
        cnt++;
    }

    return cnt+1;
}

void solve(){
    int n;
    cin >> n;
    vector<ll> f(n+1, 0);
    for(int i = 1; i<=n; i++){
        for(int j = i; j<=n; j+=i){
            f[j]++;
        }
    }
    ll ans = 0;
    for(int i = 1; i<=n; i++){
        ans += f[i];
    }
    cout << ans << nl;
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