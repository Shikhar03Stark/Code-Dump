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
        vector<string> arr(n);
        vector<vector<int>> cnt(n, vector<int>(5,0));
        for(int i = 0; i<n; i++){
            cin >> arr[i];
            for(int j = 0; j<arr[i].size(); j++){
                cnt[i][arr[i][j]-'a']++;
            }
        }
        int ans = 0;
        for(int c = 0; c<5; c++){
            vector<int> f(n);
            //cerr << (char)(c+'a') << endl;
            for(int i = 0; i<n; i++){
                f[i] = 2*cnt[i][c] - arr[i].size();
                //cerr << f[i] << " ";
            }
            sort(f.rbegin(), f.rend());
            /*for(auto& e: f){
                cerr << e << " ";
            }
            cerr << endl;*/
            int res = 0;
            int idx = 0;
            for(int i = 0; i<n; i++){
                res += f[i];
                if(res>0){
                    idx++;
                }else{
                    break;
                }
            }

            ans = max(idx, ans);
        }

        cout << ans << endl;

    }
    return 0;
}