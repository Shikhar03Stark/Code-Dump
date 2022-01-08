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
        vector<ll> arr(n);
        for(int i = 0; i<n; i++){
            cin >> arr[i];
        }
        ll sum = 0;
        vector<ll> dp(n,1);
        for(int i = 1; i<n; i++){
            if(arr[i] >= arr[i-1]){
                dp[i] = dp[i-1]+1;
            }
            sum += dp[i];
        }

        cout << sum+1 << endl;
    }
    return 0;
}