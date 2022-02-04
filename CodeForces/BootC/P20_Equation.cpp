// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

const int N = 1e3+5;

bool prime[N];

void pre(){
    for(int i = 2; i<N; i++){
        prime[i] = true;
    }

    for(int i = 2; i<N; i++){
        if(prime[i]){

            for(int j = 2*i; j<=i*i && j<N; j+=i){
                prime[j] = false;
            }
        }
    }
}

bool isprime(int n){
    if(n==2 || n==3) return true;
    for(int i = 2; i*i<=n; i++){
        if(n%i == 0) return false;
    }
    return true;
}

void solve(){
    int n;
    cin >> n;
    for(int i = n+5; i<1e9; i++){
        int j = i-n;
        if(!isprime(i) && !isprime(j) && i>=2 && j>=2){
            cout << i << " " << j << nl;
            return;
        }
    }
    return;
}

int main(){
    //pre();
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}