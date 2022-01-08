#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

int main(){
    int t;
    cin>>t;
    t=1;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(auto& e : arr){
            cin >> e;
        }

        int res = arr[0];
        for(int i = 0; i<n; i++){
            res &= arr[i];
        }

        if(find(arr.begin(), arr.end(), res) == arr.end()){
            cout << 0 << endl;
        }
        else{
            
        }
    }
    return 0;
}