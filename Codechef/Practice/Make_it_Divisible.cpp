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
        int n;
        cin >> n;
        if(n == 1){
            cout << 3 << endl;
            continue;
        }
        cout << 2;
        for(int i = 1; i<n-1; i++){
            cout << 0;
        }
        cout << 1 << endl;
    }
    return 0;
}