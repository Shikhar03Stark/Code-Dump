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

int ans(vector<int> &arr, int n){
    int low = 1, high = n;
    int res = 1;
    while(low<=high){
        int mid = low+(high-low)/2;
        bool pos = false;
        int cnt = 0;
        for(int i = 0; i<n; i++){
            if(arr[i]>=mid){
                cnt++;
            }
            if(cnt>=mid){
                pos = true;
                break;
            }
        }
        if(pos){
            res = mid;
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return res;
}

int N;

void inc(vector<int> &bit, int x, int delta){
    for(int i = x; i<=N; i += (i&-i)){
        bit[i] += delta;
    }
}

int sum(vector<int> &bit, int x){
    int ans = 0;
    for(int i = x; i>0; i -= (i&-i)){
        ans += bit[i];
    }
    return ans;
}

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    int MAXC = 0;
    for(auto& e: arr){
        cin >> e;
        MAXC = max(MAXC, e);
    }
    N = MAXC;
    vector<int> bit(MAXC+1, 0);
    vector<int> ans(n);
    for(int i = 0; i<n; i++){
        inc(bit, arr[i], 1);
        if(i){
            int pos = ans[i-1]+1;
            // cerr << "POS" << pos << nl;
            int tot = sum(bit, MAXC) - sum(bit, pos-1);
            if(tot>=pos){
                ans[i] = pos;
            }
            else{
                ans[i] = ans[i-1];
            }
        }
        else{
            ans[i] = 1;
        }

        cout << ans[i] << " ";
    }
    cout << nl;
    return;
}

int main(){
    FASTIO
    pre();
    int T=1;
    cin>>T;
    for(int z = 1; z<=T; z++){
        cout << "Case #" << z << ": ";
        solve();
    }
    return 0;
}