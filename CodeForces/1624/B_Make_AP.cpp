// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

void solve(){
    ll a, b, c;
    cin >> a >> b >> c;
    {
        double x = 2*b-c;
        if(a!=0 && a<=x){
            double m = (0.0+x)/a;
            if(m>0 && ceil(m) == floor(m)){
                cout << "YES" << nl;
                return;
            }
        }
    }
    {
        double x = (a+c)/2.0;
        if(b!=0 && b<=x){
            double m = (0.0+x)/b;
            if(m>0 && ceil(m) == floor(m)){
                cout << "YES" << nl;
                return;
            }
        }
    }
    {
        double x = 2*b-a;
        if(c!=0 && c<=x){
            double m = (0.0+x)/c;
            if(m>0 && ceil(m) == floor(m)){
                cout << "YES" << nl;
                return;
            }
        }
    }
    cout << "NO" << nl;
    return;
}

int main(){
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}