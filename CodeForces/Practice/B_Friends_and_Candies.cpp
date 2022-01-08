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
        int sum = 0;
        for(auto& e: arr){
            cin >> e;
            sum += e;
        }

        if(sum%n != 0){
            cout << -1 << endl;
        }
        else{
            int k = 0;
            for(int i = 0; i<n; i++){
                if(arr[i] > sum/n){
                    k++;
                }
            }
            cout << k << endl;
        }

    }
    return 0;
}