// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

vector<int> good;

void pre(){
    for(int i = 1; i<=1e4; i++){
        if(i%3!=0 && (i%10!=3)){
            good.push_back(i);
        }
    }
    return;
}

void solve(){
    int k;
    cin >> k;
    cout << good[k-1] << nl;
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