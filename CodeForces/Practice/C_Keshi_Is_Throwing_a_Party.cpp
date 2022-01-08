// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

bool check(vector<pair<int,int>> &arr, int k){
    int idx = 0;
    int p = 0;
    int n = arr.size();
    while(p<k && idx<n){
        int a = k-p-1, b = p;
        if(arr[idx].first>=a && arr[idx].second >= b){
            p++;
        }
        idx++;
    }
    if(p==k) return true;
    return false;
}

int solve(){
    int n;
    cin >> n;
    vector<pair<int,int>> arr(n);
    for(auto& e: arr){
        cin >> e.first >> e.second;
    }
    int low = 1, high = n;
    while(low<=high){
        int mid = (low+high)/2;
        if(check(arr, mid)){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }

    cout << high << nl;
    return 0;
}

int main(){
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}