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
struct Result {
    int output[100];
};

Result f(int n, int k){
    Result r;
    long long sum = (k*(k+1))/2;
    long long row = (n - sum)/(k*k);
    long long diff = n - sum - row*k*k;
    int out[100];
    for(int i = 0; i<k; i++){
        out[i] = max(0LL, row*(k+i+1) - k);
    }
    for(int i = 0; i<k; i++){
        long long val = row*k + i + 1;
        if(val <= diff){
            out[i] += val;
            diff -= val;
        }
        else{
            out[i] += diff;
            diff = 0;
            break;
        }
    }
    for(int i = 0; i<k; i++){
        r.output[i] = out[i];
    }
    return r;

}


void solve(){
    int n, k;
    cin >> n >> k;
    Result r = f(n, k);
    for(int i = 0; i<k; i++){
        cout << r.output[i] << " ";
    }
    cout << nl;
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