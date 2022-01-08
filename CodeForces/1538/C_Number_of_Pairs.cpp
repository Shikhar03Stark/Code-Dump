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
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> arr(n);
        for(auto& e : arr){
            cin >> e;
        }

        sort(begin(arr), end(arr));
        int cnt = 0;
        for(int i = 0; i<n; i++){
            int target = l-arr[i];
            int lb = lower_bound(begin(arr), end(arr), target) - begin(arr);

            int limit = r - arr[i];
            int up = upper_bound(begin(arr), end(arr), limit) - begin(arr);

            cnt += up - lb;
            if(l <= 2*arr[i] && 2*arr[i] <= r){
                cnt--;
            }
            /*int sum = arr[i] + arr[lb];
            while(lb < n && sum <= r){
                cnt++;
                lb++;
                sum = arr[i] + arr[lb];
            }*/
        }

        cout << cnt/2 << endl;
    }
    return 0;
}