// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;



void solve(){
    int n;
    cin >> n;
    vector<int> ods(n), evs(n), a(2*n+1);
    for(int i = 0; i<n; i++){
        cin >> ods[i];
        a[ods[i]] = i;
    }
    for(int i = 0; i<n; i++){
        cin >> evs[i];
        a[evs[i]] = i;
    }

    sort(ods.begin(), ods.end());
    sort(evs.begin(), evs.end());

    vector<int> minidx(n);

    for(int i = n-1; i>=0; i--){
        if(i==n-1){
            minidx[i] = a[evs[i]];
        }
        else{
            minidx[i] = min(a[evs[i]], minidx[i+1]);
        }
        //cerr << minidx[i] << " ";
    }
    //cerr << nl;

    int ans = 2*n+1;
    for(int i = 0; i<n; i++){
        ans = min(ans, a[ods[i]]+minidx[i]);
    }
    cout << ans << nl;
    
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