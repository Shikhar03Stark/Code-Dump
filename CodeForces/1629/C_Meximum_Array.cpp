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
    for(auto& e: arr){
        cin >> e;
    }
    if(n==1){
        if(arr[0]==0){
            cout << 1 << nl << 1 << nl;
        }
        else{
            cout << 1 << nl << 0 << nl;
        }
        return;
    }
    set<int> U;
    for(int i = 0; i<=n; i++){
        U.insert(i);
    }
    unordered_map<int,int> h;
    for(int i =0 ;i<n; i++){
        h[arr[i]] = i;
    }
    int k = 0;
    vector<int> ans;
    while(k<n){
        int mex = 0;
        while(true){
            if(h.count(mex)>0 && h[mex] >= k){
                mex++;
            }
            else{
                break;
            }
        }
        ans.push_back(mex);
        for(;k<n && *U.begin()<mex; k++){
            auto itr = U.begin();
            if((itr = U.find(arr[k])) != U.end()){
                U.erase(itr);
            }
            if(*U.begin()==mex){
                break;
            }
        }
        k++;
        for(int i = 0; i<mex; i++){
            U.insert(i);
        }
    }
    cout << ans.size() << nl;
    for(auto& e: ans){
        cout << e << ' ';
    }
    cout << nl;
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