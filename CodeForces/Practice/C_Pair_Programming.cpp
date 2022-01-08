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
        int k, n, m;
        cin >> k >> n >> m;
        vector<int> seqn(n), seqm(m);
        for(auto&e : seqn){
            cin >> e;
        }
        for(auto& e: seqm){
            cin >> e;
        }

        int i=0, j = 0;
        bool possible = true;
        vector<int> ans;
        for(int a = 0; a<n+m; a++){
            if(i < n && seqn[i] == 0){
                ans.push_back(seqn[i]);
                i++;
                k++;
            }
            else if(j < m && seqm[j] == 0){
                ans.push_back(seqm[j]);
                j++;
                k++;
            }
            else if(i<n && seqn[i] <= k){
                ans.push_back(seqn[i]);
                i++;
            }
            else if(j < m && seqm[j] <= k){
                ans.push_back(seqm[j]);
                j++;
            }
            else{
                possible = false;
                break;
            }

        }

        if(possible){
            for(auto& e: ans){
                cout << e << ' ';
            }
            cout << endl;
        }
        else{
            cout << -1 << endl;
        }
    }
    return 0;
}