#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n, p, k;
        cin >> n >> p >> k;
        ll left = n%k;
        ll round = p%k;
        ll minCol = n/k;
        ll days = 0;
        days = minCol*round + min(left, round) + p/k +1;
        cout << days << endl;
    }
    return 0;
}