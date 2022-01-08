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
        for(auto& e: arr){
            cin >> e;
        }
        sort(begin(arr), end(arr));
        ll sum = 0;
        for(int i = 0; i<n-1; i++){
            sum += (ll)arr[i];
        }
        double a = (double)sum/(n-1);
        cout << setprecision(11) << a + arr[n-1] << endl;
    }
    return 0;
}