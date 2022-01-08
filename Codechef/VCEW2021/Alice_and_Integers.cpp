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
    for(auto& e: arr){
        cin >> e;
    }
    int ans = 0;
    for(int i = 0; i<n; i++){
        while(arr[i]%3==0){
            ans++;
            arr[i] /= 3;
        }
        //ans = max(ans, cnt);
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