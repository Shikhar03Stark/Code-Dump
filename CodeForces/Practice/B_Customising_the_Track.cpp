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
        ll sum = 0;
        for(int i = 0; i<n; i++){
            cin >> arr[i];
            sum += arr[i];
        }

        ll k = sum%n;
        cout << k*(n-k) << endl;
    }
    return 0;
}