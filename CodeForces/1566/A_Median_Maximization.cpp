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
        int n, s;
        cin >> n >> s;
        double k;
        k = (0.0+s)/(n-(n-1)/2);
        //dev(k);
        k = ceil(k);
        //dev(k);
        double tot = k*(n-(n-1)/2);
        double diff = tot - s;
        //dev(diff);
        k -= ceil(diff/(n-(n-1)/2));

        cout << (int)max(0,(int)k) << endl;
    }
    return 0;
}