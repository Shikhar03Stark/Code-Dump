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
    vector<vector<int>> arr(n);
    for(int i = 0; i<n; i++){
        int k;
        cin >> k;
        for(int j = 0; j<k; j++){
            int data;
            cin >> data;
            arr[i].push_back(--data);
        }
    }
    vector<bool> kingdom(n, false), daughter(n, false);
    int left = -1;
    for(int i = 0; i<n; i++){
        bool found = false;
        for(int j = 0; j<arr[i].size(); j++){
            if(kingdom[arr[i][j]]==false){
                found = true;
                kingdom[arr[i][j]] = true;
                break;
            }
        }
        if(!found) left = i;
    }
    if(left==-1){
        cout << "OPTIMAL" << nl;
    }
    else{
        bool opti = true;
        for(int i = 0; i<n; i++){
            if(kingdom[i] == false){
                opti = false;
                cout << "IMPROVE" << nl;
                cout << left+1 << " " << i+1 << nl;
                return;
            }
        }
        if(opti){
            cout << "OPTIMAL" << nl;
        }
    }
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