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

ll cnt(vector<int> &aseg, vector<int> &bseg, int x, int y){
    ll col = 0, row = 0;
    for(int i = 0; i<aseg.size(); i++){
        col += max(0, aseg[i]-x+1);
    }
    for(int i = 0; i<bseg.size(); i++){
        row += max(0, bseg[i]-y+1);
    }

    return col*row;
}

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }
    for(int i = 0; i<m; i++){
        cin >> b[i];
    }
    vector<int> aseg, bseg;
    int seg = 0;
    for(int i = 0; i<n; i++){
        if(a[i]==0 && seg>0){
            aseg.push_back(seg);
            seg = 0;
        }
        else if(a[i]==1){
            seg++;
        }
    }
    if(seg>0){
        aseg.push_back(seg);
        seg = 0;
    }
    for(int i = 0; i<m; i++){
        if(b[i]==0 && seg>0){
            bseg.push_back(seg);
            seg = 0;
        }
        else if(b[i]==1){
            seg++;
        }
    }
    if(seg>0){
        bseg.push_back(seg);
        seg = 0;
    }
    ll ans = 0;
    for(int i = 1; i*i<=k; i++){
        if(k%i == 0){
            int x = i, y = k/i;
            ans += cnt(aseg, bseg, x, y) + (x!=y?cnt(aseg, bseg, y, x):0);
        }
    }
    cout << ans << nl;
    return;
}

int main(){
    FASTIO
    pre();
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}