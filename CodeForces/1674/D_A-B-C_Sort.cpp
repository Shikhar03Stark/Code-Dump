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
    vector<int> arr(n);
    for(auto& e: arr){
        cin >> e;
    }
    vector<vector<int>> p;
    if(n%2){
        p.push_back({arr[0]});
        for(int i = 1; i<n; i += 2){
            p.push_back({arr[i], arr[i+1]});
        }
    }
    else{
        for(int i = 0; i<n; i+=2){
            p.push_back({arr[i], arr[i+1]});
        }
    }
    vector<int> ans;
    for(auto& x: p){
        if(x.size() == 1){
            ans.push_back(x[0]);
        }
        else{
            if(x[0]>x[1]){
                ans.push_back(x[1]);
                ans.push_back(x[0]);
            }
            else{
                ans.push_back(x[0]);
                ans.push_back(x[1]);
            }
        }
    }
    bool sorted = true;
    for(int i = 1; i<n; i++){
        if(ans[i] < ans[i-1]){
            sorted = false;
            break;
        }
    }
    cout << (sorted?"YES":"NO") << nl;
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