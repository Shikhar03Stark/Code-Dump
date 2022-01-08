#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

ll result(ll n){
    return n+1 + (n/2)*n - (n/2)*(n/2);
}

int solve(){
    ll n;
    cin >> n;
    int low = 0, high = 1e9;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(result(mid) >= n){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    cout << low << endl;
    return 0;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}