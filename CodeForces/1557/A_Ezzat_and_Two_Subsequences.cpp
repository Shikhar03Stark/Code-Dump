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
        vector<double> arr(n);
        for(auto& e: arr){
            cin >> e;
        }

        sort(begin(arr), end(arr));

        double a = arr[0];
        double mean = 0;
        for(int i = 0; i<n; i++){
            mean += arr[i];
        }
        mean /= n;
        double ans = n*(mean - a);

        cout << ans << endl;

    }
    return 0;
}