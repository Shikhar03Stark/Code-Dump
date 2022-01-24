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
    vector<vector<int>> slot(n, vector<int>(5, false));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<5; j++){
            cin >> slot[i][j];
        }
    }

    bool pos = false;
    for(int i = 0; i<5; i++){
        for(int j = i+1; j<5; j++){
            int na = 0, nb = 0, eq = 0;
            for(int k = 0; k<n; k++){
                if(slot[k][i]&&slot[k][j]){
                    eq++;
                }
                else if(slot[k][i]){
                    na++;
                }
                else if(slot[k][j]){
                    nb++;
                }
                else{
                    break;
                }
            }

            if(na+nb+eq==n){
                if(na==nb && na==n/2){
                    pos = true;
                }
                if(na<=n/2 && nb<=n/2){
                    pos = true;
                }
            }
        }
    }

    if(pos){
        cout << "YES" << nl;
    }
    else{
        cout << "NO" << nl;
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