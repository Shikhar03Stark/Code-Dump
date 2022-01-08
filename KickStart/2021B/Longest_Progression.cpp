#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

int solve(vector<int>& arr, int idx, int diff, bool changed = false){
    if(arr.size()-idx <= 1){
        return 0;
    }
    if(changed){
        int last = diff;
        int streak = 1;
        int ni = idx;
        for(int i = idx; i<arr.size(); i++){
            if(last != arr[i] - arr[i-1]){
                ni = i;
                break;
            }
            ni = i;
            streak++;
        }

        return streak;
    }
    else{
        int last = diff;
        int streak = 1;
        int ni = idx;
        for(int i = idx; i<arr.size(); i++){
            if(last != arr[i] - arr[i-1]){
                ni = i;
                break;
            }
            ni = i;
            streak++;
        }

        //chenge
        return max(streak + solve(arr, ni+1, diff, true), streak + solve(arr, ni, arr[ni]-arr[ni-1], false));

    }
}

int main(){
    int t;
    cin>>t;
    for(int z = 1; z<=t; z++){
        cout << "Case #" << z << ": ";
        int n;
        cin >> n;
        vector<int> arr(n);
        for(auto& e : arr){
            cin >> e;
        }

       cout << solve(arr, 1, arr[1]-arr[0]) << endl;
    }
    return 0;
}