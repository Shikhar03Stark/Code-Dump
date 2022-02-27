// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

vector<int> primes;
const int N = 1e6;
vector<bool> p(N+1, true);
int sz;

void pre(){
    p[0] = p[1] = false;
    for(int i = 2; i*i<=N; i++){
        if(p[i]){
            for(int j = i*i; j<N; j*= i){
                p[i] = false;
            }
        }
    }
    for(int i = 2; i<N; i++){
        primes.push_back(i);
    }
    sz = primes.size();
    for(int i = 0; i<sz; i++){
        if(n%primes[i] != 0){
            
        }
    }
    return;
}

void solve(){
    ll n;
    cin >> n;

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