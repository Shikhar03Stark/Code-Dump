// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

const int psz = 1e7+1;

vector<bool> p(psz, true);
vector<int> prime;

void pre(){
    p[0] = p[1] = false;
    for(int i = 2; i*i<=psz; i++){
        if(p[i]){
            for(int j = i*i; j<=psz; j += i){
                p[j] = false;
            }
        }
    }

    for(int i = 2; i<psz; i++){
        if(p[i])
            prime.push_back(i);
    }
    return;
}

void solve(){
    int n;
    cin >> n;
    int cnt = 0;
    int pz = prime.size();
    // cerr << pz << nl;
    // for(int i = 0; i<10; i++){
    //     cerr << prime[i] << " ";
    // }
    // cerr << nl;
    for(int i = 0; prime[i]<=n && i<pz; i++){
        if(p[prime[i]-2]){
            cnt++;
        }
    }
    cout << cnt << nl;
    return;
}

int main(){
    FASTIO
    pre();
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}