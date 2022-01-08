// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

bool isgood(vector<vector<int>> &shop, int a){
    int m = shop.size(), n = shop[0].size();
    cerr << "isgood " << a << endl;
    for(int i = 0; i<m; i++){
        int cnt = 0;
        for(int j = 0; j<n; j++){
            if(shop[i][j] >= a){
                cnt++;
            }
        }
        if(cnt>=2) return true;
    }

    return false;
}

int solve(){
    int n, m;
    cin >> m >> n;
    int low = 1, high = 1;
    vector<vector<int>> shop(m, vector<int>(n));
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            cin >> shop[i][j];
            high = max(high, shop[i][j]);
        }
    }
    cerr << "IN done" << nl;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(isgood(shop, mid)){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }

    cout << low << endl;


    return 0;
}

int main(){
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}