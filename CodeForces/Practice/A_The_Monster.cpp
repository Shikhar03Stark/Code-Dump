// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

void pre(){
    
    return;
}

int gcd(int a, int b, int &x, int &y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int g = gcd(b, a%b, x1, y1);
    x = y1;
    y = x1 - y1*(a/b);
    return g;
}

bool find_any(int a, int b, int c, int &x0, int &y0){
    int g = gcd(a, b, x0, y0);
    if(c%g){
        return false;
    }
    x0 *= c/g;
    y0 *= c/g;
    if(a<0) x0 = -x0;
    if(b<0) y0 = -y0;
    return true;
}

void solve(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int ans = INT_MAX;
    for(int i = 0; i<=100; i++){
        for(int j = 0; j<=100; j++){
            if(b + i*a == d + j*c){
                ans = min(ans, b+i*a);
            }
        }
    }
    cout << (ans==INT_MAX?-1:ans) << nl;
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