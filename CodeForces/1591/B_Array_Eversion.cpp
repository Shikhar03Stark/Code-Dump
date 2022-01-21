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
    vector<int> arr(n);
    int dest = -1;
    for(auto& e: arr){
        cin >> e;
        dest = max(dest, e);
    }
    stack<int> S;
    vector<int> l(n, -1);
    for(int i = 0; i<n; i++){
        if(S.empty()){
            l[i] = -1;
            S.push(i);
        }
        else if(arr[i] < arr[S.top()]){
            l[i] = S.top();
            //S.pop();
            S.push(i);
        }
        else{
            while(!S.empty() && arr[i] >= arr[S.top()]){
                S.pop();
            }
            if(!S.empty()){
                l[i] = S.top();
            }
            S.push(i);
        }
    }
    int idx = n-1;
    int ans = 0;
    while(arr[idx] != dest){
        idx = l[idx];
        ans++;
    }
    cout << ans << nl;
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