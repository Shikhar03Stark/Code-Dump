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
        for(auto &e : arr){
            cin >> e;
        }

        int min = INT_MAX, max = INT16_MIN;
        for(int i = 0; i<n; i++){
            if(min > arr[i]){
                min = arr[i];
            }
            if(max < arr[i]){
                max = arr[i];
            }
        }

        cout << 2*(max-min) << endl;
    }
    return 0;
}