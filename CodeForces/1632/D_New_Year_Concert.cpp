// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

const int N = 1e6+5;

vector<bool> p(N, true);
vector<int> primes;
void pre(){
    for(int i = 2; i*i<N; i++){
        if(p[i]){
            primes.push_back(i);
            //p[i] = true;
            for(int j = i*i; j<N; j+=i){
                p[j] = false;
            }
        }
    }
}

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto& e: arr){
        cin >> e;
    }
    vector<int> g(n, 1);
    vector<int> dp(n, 0);
    int idx=primes.size()-1;
    if(arr[0] == 1){
        dp[0] = 1;
        arr[0] = primes[idx--];
    }
    g[0] = arr[0];
    for(int i = 1; i<n; i++){
        if(__gcd(arr[i-1], arr[i]) == 2){
            arr[i] = primes[idx--];
            g[i] = __gcd(g[i-1], arr[i]);
            dp[i] = dp[i-1]+1;
        }
        else if(arr[i] == 1){
            arr[i] = primes[idx--];
            g[i] = __gcd(g[i-1], arr[i]);
            dp[i] = dp[i-1]+1;
        }
        else{
            dp[i] = dp[i-1];
            g[i] = __gcd(g[i-1], arr[i]);
        }
    }
    for(auto& e: dp){
        cout << e << " ";
    }
    cout << nl;
    return;
}

int main(){
    int T=1;
    pre();
    cerr << primes.size() << nl;
    for(int i = 0; i<10; i++){
        cerr << primes[i] << " ";
    }
    cerr << nl;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}