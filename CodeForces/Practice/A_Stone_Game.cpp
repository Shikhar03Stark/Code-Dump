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
        int a = min_element(arr.begin(), arr.end()) - arr.begin(), b = max_element(arr.begin(), arr.end()) - arr.begin();
        if(a>b){
            swap(a,b);
        }
        int ans = min({n-a, b+1, a+1+n-b});
        cout << ans << endl;
    }
    return 0;
}