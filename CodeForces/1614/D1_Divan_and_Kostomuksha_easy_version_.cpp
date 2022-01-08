#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

int solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto& e: arr){
        cin >> e;
    }
    sort(arr.rbegin(), arr.rend());
    int tot = arr[0];
    cerr << arr[0] << " ";
    for(int i = 1; i<n; i++){
        sort(arr.begin()+i, arr.end(), [&](int a, int b){
            return __gcd(a,arr[i-1]) > __gcd(b,arr[i-1]);
        });
        tot += __gcd(tot, arr[i]);
        cerr << arr[i] << " ";
    }
    cerr << endl;
    cout << tot << endl;
    return 0;
}

int main(){
    solve();
    return 0;
}