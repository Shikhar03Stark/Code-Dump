// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

const ll MAX = 1e12;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for(auto& e: arr){
        cin >> e;
    }
    sort(arr.begin(), arr.end());
    vector<bool> c(n, false);
    int r = upper_bound(arr.begin(), arr.end(), 0) - arr.begin();
    int l = -1;
    if(r>0){
        int t = r;
        while(t>=0 && arr[t]>=0){
            t--;
        }
        if(t>=0){
            l = t;
        }
    }
    int npos = n-r;
    int nneg = (l==-1)?0:l+1;
    if(npos>0 && npos%k == 0){
        for(int i = n-1; i>=0 && i>=n-k; i--){
            c[i] = true;
        }
    }
    else if(npos > 0){
        int rem = npos%k;
        for(int i = n-1; i>=0 && i>=n-rem; i--){
            c[i] = true;
        }
    }

    if(nneg > 0 && nneg%k == 0){
        for(int i = 0; i<k; i++){
            c[i] = true;
        }
    }
    else if(nneg > 0){
        int rem = nneg%k;
        for(int i = 0; i<rem; i++){
            c[i] = true;
        }
    }

    bool fin = false;
    ll dist = 0;
    while(!fin){
        if((l<0 || c[l]) && (r>=n || c[r])){
            ll ans = (l>=0?-arr[0]:MAX);
            ans = min(ans, (r<n?arr[n-1]:MAX));
            dist += ans;
            fin = true;
        }
        else{
            if(l-k+1>=0 && !c[l]){
                l -= k-1;
                dist -= 2*arr[l];
                l--;
            }
            if(r+k-1<n && !c[r]){
                r += k-1;
                dist += 2*arr[r];
                r++;
            }
        }
    }

    cout << dist << nl;

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