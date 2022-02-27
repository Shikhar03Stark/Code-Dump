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

void solve(){
    int n;
    cin >> n;
    vector<int> arr(2*n);
    int od = 0, ev = 0;
    for(auto& e: arr){
        cin >> e;
        if(e%2){
            od++;
        }
        else{
            ev++;
        }
    }
    if(od==ev){
        cout << "Yes" << nl;
    }
    else{
        cout << "No"  << nl;
    }

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