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
        int x, y, k;
        cin >> x >> y >> k;
        int a1 = (x-1) + (y-1)*x;
        int a2 = (y-1) + (x-1)*y;

        if(a1 == k || a2 == k){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}