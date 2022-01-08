// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

const int sz = 1e6+5;
bool prime[sz];

void pre(){
    for(int i = 2; i<sz; i++){
        prime[i] = true;
    }
    for(int i = 2; i*i<sz;i++){
        for(int j = i*i; j<sz; j+=i){
            prime[j] = false;
        }
    }

}

void solve(){
    int n, e;
    cin >> n >> e;
    vector<int> arr(n);
    for(auto& d: arr){
        cin >> d;
    }
    vector<vector<int>> ap(e);
    for(int i = 0; i<n; i++){
        ap[i%e].push_back(arr[i]);
    }
    ll cnt = 0;
    for(auto& row: ap){
        int n = row.size();
        // for(auto& p: row){
        //     cerr << p << " ";
        // }
        // cerr << nl;
        ll prev = 0;
        int i = 0;
        for(int i = 0; i<n; i++){
            if(!prime[row[i]]){
                if(row[i] == 1){
                    prev++;
                }
                else{
                    prev = 0;

                }
            }
            else{
                int j = i+1;
                ll next = 0;
                while(j<n && row[j] == 1){
                    j++;
                    next++;
                }
                cnt += (prev+1)*(next+1) - 1;
                prev = next;
                i = j-1;
            }
        }
        //cerr << nl;
    }
    // cerr << nl;
    cout << cnt << nl;

    return;
}

int main(){
    pre();
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}