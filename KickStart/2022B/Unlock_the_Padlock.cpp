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

ll cnt(vector<ll> &arr, int left, int right, int val, ll d){
    int n = arr.size();
    if(left == 0 && right == n-1){
        return min((d+val)%d, (d-val)%d);
    }
    else if(left == 0 && right < n-1){
        int r = right+1;
        while(r+1<n && arr[r+1] == arr[r]){
            r++;
        }
        ll d2 = min((d+arr[r]-val)%d, (d+val-arr[r])%d);
        return d2 + cnt(arr, left, r, arr[r], d);
    }
    else if(left > 0 && right == n-1){
        int l = left-1;
        while(l-1>=0 && arr[l-1] == arr[l]){
            l--;
        }
        ll d1 = min((d+arr[l]-val)%d, (d+val-arr[l])%d);
        return d1 + cnt(arr, l, right, arr[l], d);
    }
    else{
        int l = left-1;
        while(l-1>=0 && arr[l-1] == arr[l]){
            l--;
        }
        ll d1 = min((d+arr[l]-val)%d, (d+val-arr[l])%d);

        int r = right+1;
        while(r+1<n && arr[r+1] == arr[r]){
            r++;
        }
        ll d2 = min((d+arr[r]-val)%d, (d+val-arr[r])%d);

        if(d1 == d2){
            if(arr[l] == arr[r]){
                return d1 + cnt(arr, l, r, arr[l], d);
            }
            return d1 + min(cnt(arr, l, right, arr[l], d), cnt(arr, left, r, arr[r], d));
        }
        return min(d1+cnt(arr, l, right, arr[l], d), d2+cnt(arr, left, r, arr[r], d));
    }
}

ll f(vector<ll> &arr, int left, int right, ll d){
    if(left>right) return 0;
    int lc = left, rc = right, n = arr.size();
    while(lc+1<n && arr[lc+1] == arr[lc]) lc++;
    while(rc-1>=0 && arr[rc-1] == arr[rc]) rc--;
    if(lc >= rc) return min( (d+arr[lc])%d, (d-arr[lc])%d );
    ll d1 = min((d+arr[left])%d, (d-arr[left])%d);
    ll d2 = min((d+arr[right])%d, (d-arr[right])%d);

    return min(d1 + f(arr, lc+1, right, d), d2 + f(arr, left, rc-1, d));
}

void solve(){
    ll n, d;
    cin >> n >> d;
    vector<ll> arr(n);
    for(auto& e: arr){
        cin >> e;
    }
    ll ans = INT_MAX;
    // set<pair<ll,ll>> S;
    // for(int i = 0; i<n; i++){
    //     vector<ll> t = arr;
    //     int l = i, r = i;
    //     while(l-1 >= 0 && t[l-1] == t[l]) l--;
    //     while(r+1 < n && t[r+1] == t[r]) r++;
    //     if(S.find({l, r}) == S.end()){
    //         ans = min(ans, cnt(t, l, r, t[l], d));
    //         S.insert({l, r});
    //     }
    // }

    cout << f(arr, 0, n-1, d) << nl;

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