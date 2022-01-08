// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

int solve(){
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n,0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> arr[i][j];
        }
    }
    vector<int> cars(n,1);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(arr[i][j] == 0){
                if(cars[i] != 0) cars[i] = 1;
                if(cars[j] != 0) cars[j] = 1;
            }
            else if(arr[i][j] == 1){
                cars[i] = 0;
                if(cars[j] != 0) cars[j] = 1;
            }
            else if(arr[i][j] == 2){
                cars[j] = 0;
                if(cars[i] != 0) cars[i] = 1;
            }
            else if(arr[i][j] == 3){
                cars[i] = cars[j] = 0;
            }
        }
    }

    int sum = 0;
    for(int i = 0; i<n; i++){
        if(cars[i] != -1) sum += cars[i];
    }
    cout << sum << endl;
    for(int i = 0; i<n; i++){
        if(cars[i]==1){
            cout << i+1 << " ";
        }
    }
    return 0;
}

int main(){
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}