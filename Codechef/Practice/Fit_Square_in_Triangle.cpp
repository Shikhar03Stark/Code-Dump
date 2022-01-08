#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

vector<int> dp(10001, -1);

int solve(int n){
    if(n <= 1){
        return 0;
    }
    if(dp[n] != -1){
        return dp[n];
    }

    return dp[n] = n/2 + 2*solve(n/2);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int b;
        cin >> b;
        if(b == 1){
            cout << 0 << endl;
        }
        else{
            int x = b-2;
            x /= 2;
            cout << x*(x+1)/2 << endl;
        }
    }
    return 0;
}