#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

int main(){
    int n,l;
    cin >> n >> l;
    vector<int> arr(n);
    for(auto&e:arr){
        cin >> e;
    }
    sort(arr.begin(), arr.end());
    double maxd = -1;//max(arr[0], l-arr[n-1]);
    for(int i = 1; i<n; i++){
        maxd = max((double)arr[i]-arr[i-1], maxd);
    }
    double ans = max({maxd/2, (double)arr[0], (double)l-arr[n-1]});
    printf("%0.12f\n", ans);
    return 0;
}