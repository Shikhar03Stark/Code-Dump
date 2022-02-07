// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

void solve(){
    int m;
    cin >> m;
    vector<vector<int>> arr(m);
    vector<vector<int>> ans(m);

    map<int,pair<int,int>> h;
    for(int i = 0; i<m; i++){
        int sz;
        cin >> sz;
        vector<int> t(sz);
        for(auto& e: t){
            cin >> e;
            h[e] = {h[e].first+1, h[e].second+1};
        }
        ans[i] = vector<int>(sz, -1);
        arr[i] = t;
    }
    bool pos = true;
    for(auto& e: h){
        if(e.second.first%2==1){
            pos= false;
            break;
        }
    }
    if(!pos){
        cout << "NO" << nl;
    }
    else{
        auto it = h.begin();
        for(;it != h.end(); it++){
            it->second.first /= 2;
            it->second.second /= 2;
        }
        for(int i = 0; i<m; i++){
            int k = arr[i].size();
            int l = 0, r = 0;
            for(int j = 0; j<arr[i].size(); j++){
                if(h[arr[i][j]].first>0){
                    //L
                    if(2*l==k){
                        //Try R
                        if(h[arr[i][j]].second > 0){
                            //DO R
                            r++;
                            ans[i][j] = 1;
                            h[arr[i][j]].second--;
                        }
                        else{
                            //Imp
                            cout << "NO" << nl;
                            return;
                        }
                    }
                    else{
                        l++;
                        ans[i][j] = 0;
                        h[arr[i][j]].first--;
                    }
                }
                else{
                    //R
                    if(2*r==k){
                        //Try L
                        if(h[arr[i][j]].first > 0){
                            //Do L
                            ans[i][j] = 0;
                            h[arr[i][j]].first--;
                            l++;
                        }
                        else{
                            //Imp
                            cout << "NO" << nl;
                            return;
                        }
                    }
                    else{
                        r++;
                        ans[i][j] = 1;
                        h[arr[i][j]].second--;
                    }
                }
            }
        }

        cout << "YES" << nl;
        for(auto& row: ans){
            for(auto&e : row){
                if(e == 0){
                    cout << 'L';
                }
                else{
                    cout << 'R';
                }
            }
            cout << nl;
        }
    }

    return;
}

int main(){
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}