#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;
int main(){
    FASTIO
    int t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        ll *arr = new ll[n];
        for(int i = 0; i<n; i++){
            cin >> arr[i];
        }

        int min = INT_MAX;
        for(int i = 0; i<n; i++){
            if(min > arr[i]){
                min = arr[i];
            }
        }

        cout << k-min << endl;
    }
    return 0;
}