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
        int diff = 0;
        for(int i = 0; i<n; i++){
            diff = max(diff, arr[i]-i-1);
        }
        cout << diff << endl;
    }
    return 0;
}