#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(auto&e:arr){
            cin >> e;
        }
        int q;
        cin >> q;
        vector<pair<int,int>> que(q);
        for(auto& p:que){
            cin >> p.first >> p.second;
        }

        vector<vector<int>> state(n+1, vector<int>(n));
        map<int,int> h;
        for(int i = 0; i<n; i++){
            state[0][i] = arr[i];
            h[arr[i]]++;
        }
        for(int k = 1; k<=n; k++){
            for(int i = 0; i<n; i++){
                state[k][i] = h[state[k-1][i]];
            }
            h.clear();
            for(int i = 0; i<n; i++){
                h[state[k][i]]++;
            }
        }

        for(auto& p:que){
            if (p.second>n) {
                cout << state[n][p.first-1] << endl;
            }
            else{
                cout << state[p.second][p.first-1] << endl;
            }
        }
    }
    return 0;
}