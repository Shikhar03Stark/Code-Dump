#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

int solve(vector<vector<int>>& words, int idx, int n, int a, int b, int c, int d, int e){
    if(idx >= n){
        return 0;
    }
    

}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        vector<string> sent(n);
        vector<vector<int>> meta(n, vector<int>(5, 0));
        for(int i = 0; i<n; i++){
            cin >> sent[i];
            for(int j =0 ;j<sent[i].size(); j++){
                meta[i][sent[i][j] - 'a']++;
            }
        }
        int ans = solve(meta, 0, 0, 0, 0, 0, 0, e);
    }
    return 0;
}