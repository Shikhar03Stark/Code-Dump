// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

int bits(int n, int j){
    if(n == 0) return 0;
    int g = n/(1<<(j+1));
    int rem = n%(1<<(j+1));
    int r = 0;
    if(rem >= (1<<j)){
        r = rem-(1<<j)+1;
    }
    return g*(1<<j) + r;
}

int solve(){
    int l, r;
    cin >> l >> r;
    if(l == r){
        cout << 0 << nl;
        return 0;
    }
    int j = 0;
    while((1<<j)<r){    
        j++;
    }
    if((1<<j)>=r)
        j--;

    vector<int> freq(32, 0);
    for(int i = 0; i<31; i++){
        freq[i] = bits(r, i) - bits(l-1, i);
    }
    int maxi = *max_element(freq.begin(), freq.end());
    cout << (r-l+1)-maxi << nl;
    //cerr << j << nl;
    //cerr << (1<<j) << nl;
    //cerr << (r - (1<<j)) << " " << ((1<<j) - l) << " " << (r-l-(1<<j)+(1<<(j-1))) << nl;
    //cerr << (1<<j)-l << " " << r+1-(1<<j) << " ";
    /*
    int ans = INT_MAX;
    if( (1<<(j-1)>l) || (1<<(j+1)<=r)){
        if(j>0 && (1<<(j-1)>l)){
            ans = min(ans, r-l+1-(1<<j)+(1<<(j-1)));
            //cerr << r-l+1-(1<<j)+(1<<(j-1)) << " ";
        }
        if((1<<(j+1)<=r)){
            ans  = min(ans, r-l+1-(1<<(j+1))+(1<<(j)));
            //cerr << r-l+1-(1<<(j+1))+(1<<(j)) << " ";
        }
    }
    else{
        ans = min((1<<j)-l, r+1-(1<<j));

    }
    //cerr << nl;
    if(l%2==0 && r%2==0){
        ans = min(ans, 1+(r-l+1)/2);
    }
    else{
        ans = min(ans, (r-l+1)/2);
    }
    cout << ans << nl;
    */
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