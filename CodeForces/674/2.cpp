#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n, m;
        cin >> n >> m;

        ll sym = 0;
        vector<vector<int>> tile(2, vector<int>(2));
        for(ll i = 0;i < n; i++){
            cin >> tile[0][0] >> tile[0][1] >> tile[1][0] >> tile[1][1];
            if(tile[0][1] == tile[1][0]){
                ++sym;
            }
        }

        if(m%2 != 0){
            cout << "NO" << endl;
        }
        else{
            if(sym>0){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}