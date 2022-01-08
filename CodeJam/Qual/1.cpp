#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

int main(){
    int t;
    cin>>t;
    for(int z = 1; z<=t; z++){
        cout << "Case #" << z << ": ";
        int n;
        cin >> n;
        vector<int> arr(n);
        for(auto& e:arr){
            cin >> e;
        }
        int cost = 0;
        for(int i = 0; i<n-1; i++){
            int minj = i;
            for(int j = i+1; j<n; j++){
                if(arr[minj] >= arr[j]){
                    minj = j;
                }
            }
            reverse(arr.begin()+i, arr.begin()+minj+1);
            cost += minj - i +1;
        }

        cout << cost << endl;
    }
    return 0;
}