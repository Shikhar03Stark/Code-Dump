// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

bool possible(vector<ll> arr, ll p, vector<ll> &org){
    int n = arr.size();
    for(int i = n-1; i>=2; i--){
        if(arr[i] < p) return false;
        ll d = min(org[i], arr[i]-p)/3;
        arr[i] -= 3*d;
        arr[i-1] += d;
        arr[i-2] += 2*d;
    }
    return arr[0]>=p && arr[1]>=p;
}

void solve(){
    int n;
    cin >> n;
    vector<ll> arr(n);
    for(auto& e: arr){
        cin >> e;
    }

    ll start = 0, end = 1e14+10;
    while(start<=end){
        ll mid = start + (end-start)/2;
        if(possible(arr, mid, arr)){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }

    cout << end << nl;
    
    return;
}

int main(){
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}