#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

int solve(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int ans = -1;
    for(char c = 'A'; c<='Z'; c++){
        int cnt = 0;
        int grps = 0;
        int rem = 0;
        for(int i = 0; i<n; i++){
            if(s[i] != c){
                cnt++;
            }
            else{
                if(cnt>0){
                    rem += cnt;
                    grps++;
                }
                cnt = 0;
            }
        }
        if(cnt!=n){
            if(grps<=k){
                ans = max(ans, grps);
            }
            else{
                
            }
        }
    }
    cout << ans << endl;
    return 0;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}