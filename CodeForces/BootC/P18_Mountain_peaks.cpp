// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

void badd(vector<int> &bit, int idx, int delta){
    int n = bit.size();
    for(int i = idx; i<n; i+=(i&-i)){
        bit[i] += delta;
    }
}

int query(vector<int> &bit, int n){
    int ans = 0;
    for(int i = n; i>0; i-=(i&-i)){
        ans += bit[i];
    }
    return ans;
}

vector<int> factor(int n){
    vector<int> ans;
    for(int i = 1; i*i<=n; i++){
        if(n%i==0){
            if(i==n/i){
                ans.push_back(i);
            }
            else{
                ans.push_back(i);
                ans.push_back(n/i);
            }
        }
    }

    return ans;
}

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto& e: arr){
        cin >> e;
    }
    vector<int> bit(n+1, 0);
    for(int i = 1; i<n-1; i++){
        if(arr[i-1] < arr[i] && arr[i] > arr[i+1]){
            badd(bit, i+1, 1);
        }
    }
    int day = 0;
    for(auto& e: factor(n)){
        bool haspeak = true;
        for(int i = 1; i+e-1<=n; i += e){
            int peaks = query(bit, i+e-1) - query(bit, i-1);
            if(peaks == 0){
                haspeak = false;
                break;
            }
        }
        if(haspeak){
            day = max(day, n/e);
        }
    }
    cout << day << nl;

    return;
}

int main(){
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}