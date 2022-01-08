// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

int solve(){
    ll a, s;
    cin >> a >> s;
    ll na, ns;
    ll n = max(na=floor(log10(a))+1, ns=floor(log10(s))+1);
    vector<ll> A(n*2), S(n*2), B(n*2);
    for(int i = 0; i<n && a>0; i++){
        A[i] = a%10;
        a /= 10;
    }
    for(int i = 0; i<n && s>0; i++){
        S[i] = s%10;
        s /= 10;
    }

    bool pos = true;
    ll ap = 0, sp = 0, bp = 0;
    while(ap < n){
        if(S[sp] < A[ap]){
            if(sp>n){
                pos = false;
                break;
            }
            int sum = S[sp+1]*10 + S[sp];
            if(sum < 10){
                pos = false;
                break;
            }
            if(sum - A[ap] > 9 || sum - A[ap] < 0){
                pos = false;
                break;
            }
            B[bp] = sum - A[ap];
            sp+=2;
            ap++;
            bp++;
        }
        else{
            B[bp] = S[sp] - A[ap];
            bp++;
            sp++;
            ap++;
        }
    }

    if(!pos){
        cout << -1 << endl;
        return 0;
    }

    bool num = false;
    for(int i = 2*n-1; i>=0; i--){
        if(B[i]!=0){
            num = true;
        }
        if(num){
            cout << B[i];
        }
    }
    if(num==false) cout << 0;
    cout << nl;

    return 0;
}

int main(){
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}