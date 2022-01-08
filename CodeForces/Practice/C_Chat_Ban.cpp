#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

ll sum(ll i, ll k){
    if(i<=k){
        ll sum = i*(i+1)/2;
        return sum;
    }
    else{
        i = i-k;
        ll sum = k*(k+1)/2 + k*i - i*(i+1)/2;
        return sum;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        ll k, x;
        cin >> k >> x;
        ll sk = k*(k+1)/2;
        ll start = 1, end = 2*k-1;
        while(start <= end){
            ll mid = start + (end-start)/2;
            if(sum(mid, k) <= x){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        //cerr << start << endl;
        if( (sum(start,k) <= x) || (sum(end,k) == x) ){
            cout << start-1 << endl;
        }
        else{
            cout << start << endl;
        }
    }
    return 0;
}