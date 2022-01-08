#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

int dfs(int node, int &level, int idx, vector<int> &cost, vector<int> &b, vector<int> &p){
    if(idx >= p.size()){
        return p.size();
    }
    cost[node] = level;
    int lastIdx = idx+1;
    int k = idx+1;
    int cnt = 0;
    while(lastIdx<p.size()){
        if(b[p[lastIdx]] == p[idx]){
            level++;
            lastIdx = dfs(p[lastIdx], level, lastIdx, cost, b, p);
            k = lastIdx;
            cnt++;
        }
        else{
            lastIdx++;
        }
    }
    return k;
}

int solve(){
    int n;
    cin >> n;
    int root = 0;
    vector<int> b(n);
    for(int i = 0; i<n; i++){
        cin >> b[i];
        b[i]--;
        if(i==b[i]) root = i;
    }
    vector<int> p(n);
    for(int i = 0; i<n; i++){
        cin >> p[i];
        p[i]--;
    }
    vector<int> d(n,-1);
    bool pos = true;
    if(p[0] == root){
        d[p[0]] = 0;
        for(int i = 1; i<n; i++){
            if(d[b[p[i-1]]] >= 0){
                d[p[i]] = d[p[i-1]]+1;
            }
            else{
                pos = false;
                break;
            }
            if(d[b[p[i]]] >= d[p[i]]){
                pos = false;
                break;
            }
        }
    }
    else{
        pos = false;
    }

    if(pos){
        for(int i = 0; i<n; i++){
            //cerr << d[i] << " ";
            cout << d[i]-d[b[i]] << " ";
        }
        //cerr << endl;
        cout << endl;
    }
    else{
        cout << -1 << endl;
    }

    return 0;
}

int main(){
    FASTIO
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}