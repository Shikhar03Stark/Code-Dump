#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<ll> arr(n);
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    vector<ll> dp(n);
    dp[0] = arr[0];
    for(int i = 1; i<n; i++){
        dp[i] = max(arr[i], dp[i-1]+arr[i]);
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
    return 0;
}