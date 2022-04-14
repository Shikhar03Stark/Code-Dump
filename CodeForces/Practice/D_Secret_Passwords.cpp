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
    return dsu[x]<0?x:dsu[x] = find(dsu, dsu[x]);
}

void solve(){
    int n;
    cin >> n;
    vector<string> arr(n);
    for(auto& e: arr){
        cin >> e;
    }

    vector<int> dsu(n+26, -1);

    for(int i = 0; i<n; i++){
        int sz = arr[i].size();
        for(int j = 0; j<sz; j++){
            int n1 = i+26, n2 = arr[i][j]-'a';
            int p1 = find(dsu, n1), p2 = find(dsu, n2);
            if(p1 != p2){
                if(p1>p2){
                    swap(p1, p2);
                }
                dsu[p1] += dsu[p2];
                dsu[p2] = p1;
            }
        }
    }

    int cc = 0;
    for(int i = 0; i<26; i++){
        if(dsu[i]<-1) cc++;
    }
    cout << cc << nl;
    

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