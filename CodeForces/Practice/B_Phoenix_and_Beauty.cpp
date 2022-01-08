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
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        set<int> S;
        map<int,int> h;
        for(int i = 0; i<n; i++){
            cin >> arr[i];
            //S.insert(arr[i]);
            h[arr[i]] = 1;
        }
        if(h.size() > k){
            cout << -1 << endl;
            continue;
        }
        int idx = 0;
        vector<int> ans;

        while(ans.size()<h.size()){
            if(h[arr[idx]] > 1){
                for(int i = 1; i<n && ans.size()<h.size(); i++){
                    if(h[i] == 1){
                        ans.push_back(i);
                        h[i] = 2;
                    }
                }
            }
            else{
                ans.push_back(arr[idx]);
                h[arr[idx++]] = 2;
            }
        }
        int prev = 0;
        while(idx<n){
            if(ans[prev] == arr[idx]){
                ans.push_back(ans[prev]);
                idx++;
                prev++;
            }
            else{
                ans.push_back(ans[prev]);
                prev++;
            }
        }
        cout << ans.size() << endl;
        for(auto& e: ans){
            cout << e << " ";
        }
        cout << endl;

    }
    return 0;
}