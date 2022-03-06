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

int ask(int l ,int r){
    int s;
    cout << "? " << l << " " << r << endl;
    cin >> s;
    return s;
}

void solve(){
    int n, t, k;
    cin >> n >> t >> k;
    int l = 1, r = n;
    int z = 0;
    while(l<r){
        int mid = l + (r-l)/2;
        int zr = mid-l+1-ask(l, mid);
        if(z + zr < k){
            l = mid+1;
            z += zr;
        }
        else{
            r = mid;
        }
    }
    cout << "! " << l << endl;
    return;
}

int main(){
    //FASTIO
    pre();
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}