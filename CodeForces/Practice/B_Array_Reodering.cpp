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
        vector<int> arr(n);
        for(auto&e : arr){
            cin >> e;
        }

        sort(begin(arr), end(arr), [](int a, int b){
            return a%2 < b%2;
        });

        int ans = 0;
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                ans += (__gcd(arr[i], 2*arr[j]) > 1) ? 1: 0;
            }
        }

        cout << ans << endl;
    }
    return 0;
}