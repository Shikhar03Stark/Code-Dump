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
        for(auto& e : arr){
            cin >> e;
        }

        if(arr[0] != arr[1]){
            if(arr[1] != arr[2]){
                cout << 2 << endl;
            }
            else
                cout << 1 << endl;
            continue;
        }

        for(int i = 1; i<n; i++){
            if(arr[i-1] != arr[i] ){
                cout << i+1 << endl;
                break;
            }
        }
    }
    return 0;
}