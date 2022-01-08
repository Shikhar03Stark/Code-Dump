#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

ull lcm(ull a, ull b){
    return a/__gcd(a, b)*b;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        ull x, k;
        cin >> x >> k;
        ull mini = min({lcm(x, 2*x), lcm(x, x+1), lcm(x, x+2)}), maxi = x*k*(x*k-1);
        cout << mini << " " << maxi << endl;
        /**for(int i = x; i<=k*x; i++){
            for(int j = i; j<=k*x; j++){
                cerr << lcm(i,j) << " ";
            }
            cerr << endl;
        }
        cerr << endl;**/
    }
    return 0;
}