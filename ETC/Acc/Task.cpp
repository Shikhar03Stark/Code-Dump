#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 998244353

bool isPrime(ll n){
    if(n == 2 || n == 3){
        return true;
    }
    if(n%2 == 0 || n%3 == 0){
        return false;
    }
    for(int i = 5; i*i<=n; i+=6){ // O(sqrt(n)/6)
        if(n%i == 0 || n%(i+2) == 0){
            return false;
        }
    }

    return true;
}

ll dp[2000001];

ll multiple(ll n){ //O(n)
    for(ll i = 2; i*i<=n; i++){
        if(n%i == 0){
            return i;
        }
    }

    return 1LL;
}

ll f(ll);

ll innerSigma(ll n){
    ll sum = 0;
    for(ll i = 1; i*i<=n; i++){
        if(n%i == 0){
            if(n/i == i){
                sum += f(i)%mod;
            }
            else{
                sum += (f(i)%mod + f(n/i)%mod)%mod;
            }
        }
    }
    /*
    for(ll i = 1; i<=n; i++){ //O(n)
        if(n%i == 0)
            sum += f(i)%mod; //O(i*sqrt(i))
    }*/

    return sum;
}

ll f(ll n){ //O(n sqrt(n))
    if(dp[n] != -1){
        return dp[n];
    }
    if(n == 1){
        return 0;
    }
    else if(isPrime(n)){ //O(sqrt(n)/6)
        return dp[n] = 1;
    }
    else{
        ll x = multiple(n);
        ll y = n/x;
        return dp[n] = ((y%mod * f(x)%mod)%mod + (x%mod * f(y)%mod)%mod)%mod;
    }
}

long long strange_sum (int L, int R) {
   ll ans = 0;
   memset(dp, -1, 2000001);
   for(ll i = L; i<=R; i++){ //O(n)
       ans += innerSigma(i)%mod;
   }

   return ans;
   
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i = 0; t_i < T; t_i++)
    {
        int L;
        cin >> L;
        int R;
        cin >> R;

        long long out_;
        out_ = strange_sum(L, R);
        cout << out_;
        cout << "\n";
    }
}