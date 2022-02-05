// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<string> arr(n);
    for(auto& e: arr){
        cin >> e;
    }
    if(n==1){
        cout << arr[0] << endl;
        return;
    }
    vector<string> mod(n-1);
    for(auto& e: mod){
        cin >> e;
    }
    string ans;
    for(int j = 0; j<m; j++){
        vector<int> cnt(26,0);
        for(int i = 0; i<n; i++){
            if(i<n-1){
                cnt[arr[i][j]-'a']++;
                cnt[mod[i][j]-'a']++;
            }
            else{
                cnt[arr[i][j]-'a']++;
            }
        }
        for(int i = 0; i<26; i++){
            if(cnt[i]%2==1){
                ans.push_back(i+'a');
                break;
            }
        }
    }
    //cerr << ans << nl;
    cout << ans << endl;
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