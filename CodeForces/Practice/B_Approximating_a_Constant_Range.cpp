// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

int calcLen(vector<int> &arr, int l, int r){
    int n = arr.size();
    if(l == r) return 0;
    if(r-l==1) return 2;
    int mid = (l+r)/2;
    int left = mid, right = mid+1;
    int maxRng = 0;
    if(arr[left] - arr[right] == 1){
        //left is greater
        int m = arr[right], M = arr[left];
        while(left>=0 && arr[left]>=m && arr[left]<=M){
            left--;
        }
        while(right< n && arr[right]>=m && arr[right]<=M){
            right++;
        }
        maxRng = right-left-1;
    }
    else if(arr[left]-arr[right] == -1){
        //right is greater
        int m = arr[left], M = arr[right];
        while(left>=0 && arr[left]>=m && arr[left]<=M){
            left--;
        }
        while(right< n && arr[right]>=m && arr[right]<=M){
            right++;
        }
        maxRng = right-left-1;
    }
    else{
        //both eq
        int x = arr[left];
        int lmiss = left, rmiss = right;
        int lmax = 0, rmax = 0;
        while(lmiss >=0 && arr[lmiss] != arr[lmiss+1]){
            lmiss--;
        }
        while(rmiss < n && arr[rmiss] != arr[rmiss-1]){
            rmiss++;
        }
        {
            int m = min(arr[lmiss], x), M = max(arr[lmiss], x);
            int i = lmiss;
            while(i>=0 && arr[i]>=m && arr[i]<=M){
                i--;
            }
            lmax = lmiss-i+1;
        }
        {
            int m = min(arr[rmiss], x), M = max(arr[rmiss], x);
            int i = rmiss;
            while(i<n && arr[i]>=m && arr[i]<=M){
                i++;
            }
            rmax = i-rmiss+1;
        }

        maxRng = max(lmax, rmax) + (rmiss-lmiss);
    }

    int lrange = calcLen(arr, l, mid), rrange = calcLen(arr, mid+1, r);

    return max({maxRng, lrange, rrange});
}

int solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto& e: arr){
        cin >> e;
    }
    cout << calcLen(arr, 0, n-1) << endl;
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