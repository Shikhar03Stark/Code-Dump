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

int find(vector<int> &dsu, int x){
    return (dsu[x]<0)?x:dsu[x] = find(dsu, dsu[x]);
}

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto& e: arr){
        cin >> e;
    }
    set<int> S;
    vector<int> dsu(n+1, -1);
    for(int i = 0; i<n; i++){
        auto it = S.upper_bound(arr[i]);
        if(it != S.end()){
            int node = *it;
            int p1 = find(dsu, node), p2 = find(dsu, arr[i]);
            if(p1 != p2){
                if(p1>p2){
                    swap(p1, p2);
                }
                dsu[p1] += dsu[p2];
                dsu[p2] = p1;
            }
        }
        S.insert(arr[i]);
    }
    int cnt = 0;
    for(int i = 1; i<=n; i++){
        if(dsu[i]<0){
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
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}