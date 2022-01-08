#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

int solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    map<int,int> last;
    vector<int> dp(n,0);
    for(int i = 0; i<n; i++){
        if(last.count(arr[i]-1) > 0){
            dp[i] = 1+dp[last[arr[i]-1]];
        }
        else{
            dp[i] = 1;
        }
        last[arr[i]] = i;
    }
    int idx = max_element(dp.begin(), dp.end()) - dp.begin();
    cout << dp[idx] << endl;
    int prev = INT_MAX;
    vector<int> ans;
    for(int i = idx; i>=0; i--){
        if(prev == INT_MAX){
            ans.push_back(i);
            prev = arr[i];
        }
        else if(arr[i]+1 == prev){
            ans.push_back(i);
            prev = arr[i];
        }
    }
    for(int i = ans.size()-1; i>=0; i--){
        cout << ans[i]+1 << " ";
    }
    return 0;
}

int main(){
    solve();
    return 0;
}