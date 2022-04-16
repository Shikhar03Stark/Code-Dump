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
    map<int,vector<int>> children;
    int n;
    cin >> n;
    vector<int> parent(n-1);
    for(auto& e: parent){
        cin >> e;
    }
    for(int i = 0; i<n-1; i++){
        children[parent[i]].push_back(i+2);
    }
    vector<int> arr = {1};
    for(auto& e: children){
        arr.push_back(e.second.size());
    }
    int ans =  0;
    priority_queue<int> pq;
    for(int i = 0; i<arr.size(); i++){
        pq.push(arr[i]);
    }

    while(!pq.empty()){
        int t = pq.top(); pq.pop();
        if(t>1){
            t -= 2;
            if(t>0){
                pq.push(t);
            }
            ans++;
        }
        else if(t==1){
            if(!pq.empty()){
                int t2 = pq.top(); pq.pop();
                t2--;
                if(t2>0){
                    pq.push(t2);
                }
            }
            ans++;
        }
        else{
            while(!pq.empty() && pq.top()<=0) pq.pop();
        }
    }

    cout << ans << nl;

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