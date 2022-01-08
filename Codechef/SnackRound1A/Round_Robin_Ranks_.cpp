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
        if(k == 1 || n == 2)
            cout << (n-k)*2 << endl;
        else
            cout << (n-k+(k-1)/2)*2 << endl;
    }
    return 0;
}