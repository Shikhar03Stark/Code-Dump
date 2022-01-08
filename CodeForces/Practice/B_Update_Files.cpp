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
        ull n, k;
        cin >> n >> k;
        ull comps = 1;
        ull hrs = 0;
        while(comps < k){
            comps = (comps<<1);
            hrs++;
        }
        if(comps <= n)
            hrs += (n-comps)%k==0?(n-comps)/k:(n-comps)/k+1;
        cout << hrs << endl;
    }
    return 0;
}