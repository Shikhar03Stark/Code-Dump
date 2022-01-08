#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>> M(n);
        for(int i = 0; i<n; i++){
            int size;
            cin >> size;
            M[i].resize(size);
            for(auto&e : M[i]){
                cin >> e;
            }
        }

        unsigned ll negs = 0, pos = 0;
        
    }
    return 0;
}