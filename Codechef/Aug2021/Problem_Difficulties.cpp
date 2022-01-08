#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

void solve(vector<int> &arr, int idx, int left, int right, vector<int> &taken, int &ans){
    if(idx == arr.size()){
        int prev = -1;
        //ps1
        int ps = 0;
        for(int i = 0; i<4; i++){
            if(taken[i] == 1){
                if(prev != arr[i]){
                    if(prev > 0){
                        ps++;
                    }
                    prev = arr[i];
                }
            }
        }
        prev = -1;
        for(int i = 0; i<4; i++){
            if(taken[i] == 2){
                if(prev != arr[i]){
                    if(prev > 0){
                        ps++;
                    }
                    prev = arr[i];
                }
            }
        }

        ans = max(ans, ps);
        return;
    }
    if(left > 0){
        taken[idx] = 1;
        solve(arr, idx+1, left-1, right, taken, ans);
    }
    if(right > 0){
        taken[idx] = 2;
        solve(arr, idx+1, left, right-1, taken, ans);
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<int> arr(4);
        cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];
        sort(arr.begin(), arr.end());
        int ps = 0;
        vector<int> taken(4, 0);
        int ans = 0;
        solve(arr, 0, 2, 2, taken, ans);
        cout << ans << endl;
    }
    return 0;
}