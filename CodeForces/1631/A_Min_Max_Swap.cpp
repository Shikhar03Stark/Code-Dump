// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(auto& e: a){
        cin >> e;
    }
    for(auto& e: b){
        cin >> e;
    }
    for(int i = 0 ; i<n;i++){
        if(a[i]<b[i]){
            swap(a[i], b[i]);
        }
    }
    ll ma = *max_element(a.begin(), a.end());
    ll mb = *max_element(b.begin(), b.end());
    cout << ma*mb << nl;
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