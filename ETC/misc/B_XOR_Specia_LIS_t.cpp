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
        for(auto&e:arr){
            cin >> e;
        }
        if(n%2==0){
            cout << "YES" << endl;
        }
        else{
            bool dec = false;
            for(int i = 1; i<n; i++){
                if(arr[i]<=arr[i-1]){
                    dec = true;
                    break;
                }
            }
            cout << (dec?"YES":"NO") << endl;
        }
    }
    return 0;
}