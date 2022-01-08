#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

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

        bool dense = true;
        int count = 0;
        for(int i = 0; i<n-1; i++){
            if(max(arr[i], arr[i+1]) > 2*min(arr[i], arr[i+1])){
                int ma = max(arr[i], arr[i+1]);
                int mi = min(arr[i], arr[i+1]);
                for(int i = mi+1; 2*i <= ma; i +=2){
                    count++;
                }
                //count++;
            }
        }

        cout << count <<  endl;
    }
    return 0;
}