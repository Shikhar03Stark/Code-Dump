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
        int n, m;
        cin >> n >> m;
        vector<tuple<int,int,int>> res(m);
        vector<int> vis(n+1,0);
        for(auto& r: res){
            cin >> get<0>(r) >> get<1>(r) >> get<2>(r);
            vis[get<1>(r)] = 1;
        }

        int root = 1;
        for(int i = 1; i<=n; i++){
            if(vis[i] == 0){
                root = i;
                break;
            }
        }
        for(int i = 1; i<=n; i++){
            if(i != root){
                cout << i << " " << root << endl;
            }
        }

    }
    return 0;
}