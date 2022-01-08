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
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for(auto& e: arr){
            cin >> e;
        }
        sort(begin(arr), end(arr));
        int minpt = arr[n-k];
        int idx = lower_bound(arr.begin(), arr.end(), minpt) - arr.begin();
        cout << n-idx << endl;
    }
    return 0;
}