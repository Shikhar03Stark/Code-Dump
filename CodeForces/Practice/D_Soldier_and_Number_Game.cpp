// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

const int MAXN = 5e3+1;

vector<bool> p(MAXN, true);
vector<int> primes;
vector<ll> divcnt((5e6)+1, 0);

void pre(){
    for(int i = 2; i*i<MAXN; i++){
        if(p[i]){
            for(ll j = i*i; j<MAXN; j+=i){
                p[j] = false;
            }
        }
    }

    for(int i = 2; i<MAXN; i++){
        if(p[i]) primes.push_back(i);
    }
    int sz = primes.size();
    for(int i = 1; i<5e6+1; i++){
        if(i>1){
            int k = i;
            int c = 0;
            int idx = 0;
            int d = primes[0];
            while(idx<sz && d*d <= k){
                while(k%d==0){
                    k /= d;
                    c++;
                }
                d = primes[++idx];
            }
            divcnt[i] = divcnt[i-1] + c + (k>1?1:0);
        }
        else{
            divcnt[i] = 1;
        }
    }
    return;
}

void solve(){
    int a, b;
    cin >> a >> b;
    int ans = divcnt[a] - divcnt[b];
    cout << ans << nl;
    return;
}

int main(){
    FASTIO
    pre();
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}