// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

void pre(){
    
    return;
}

ll merge(vector<int> &arr, ll left, ll mid, ll right){
    ll sz = right-left+1;
    vector<int> t(sz);
    ll i = left, j = mid+1, k = 0;
    ll count = 0;
    while(i<=mid && j<=right){
        if(arr[j] <= arr[i]){
            count += mid-i+1;
            t[k++] = arr[j++];
        }
        else{
            t[k++] = arr[i++];
        }
    }

    while(i<=mid){
        t[k++] = arr[i++];
    }
    while(j<=right){
        t[k++] = arr[j++];
    }

    for(int i = 0; i<sz; i++){
        arr[left+i] = t[i];
    }
    return count;

}

ll count_inversion(vector<int> &arr, ll left, ll right){
    if(left>=right){
        return 0;
    }
    ll mid = left + (right-left)/2;
    ll l_count = count_inversion(arr, left, mid);
    ll r_count = count_inversion(arr, mid+1, right);
    ll inv = merge(arr, left, mid, right);
    return inv+l_count+r_count;
}

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto& e: arr){
        cin >> e;
    }
    ll inv = count_inversion(arr, 0, n-1);
    // int i = 0;
    // while(i<n){
    //     int j = i;
    //     while(j+1 < n && arr[j+1] == arr[j]){
    //         j++;
    //     }
    //     inv += (j-i>0?(j-i+1):0);
    //     i = j+1;
    // }
    cout << inv << nl;
    
    return;
}

int main(){
    FASTIO
    pre();
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}