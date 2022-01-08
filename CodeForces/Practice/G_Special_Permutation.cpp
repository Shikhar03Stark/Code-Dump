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
        if(n<=3){
            cout << -1 << endl;
            continue;
        }
        for(int i = n; i>=6; i--){
            if(i%2==0){
                cout << i << " ";
            }
        }
        cout << 2 << " " << 4 << " ";
        for(int i = 1; i<=n; i+=2){
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}