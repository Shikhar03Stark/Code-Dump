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
        int n, low, high;
        cin >> n >> low >> high;
        vector<int> arr(n);
        for(auto& e: arr){
            cin >> e;
        }
        sort(arr.begin(), arr.end());
        int minl = 0, minr = 1;
        for(;minl<n; minl++){
            int target = low-arr[minl];
            minr = lower_bound(arr.begin()+minl+1, arr.end(), target) - arr.begin();
            if(minr < n){
                break;
            }
        }
        

        int ans = (n*(n-1))/2 - minl*(n-1) - (minr-minl-1) - maxl*(n-1) - (maxr-maxl-1);
        cout << ans << endl;
    }
    return 0;
}