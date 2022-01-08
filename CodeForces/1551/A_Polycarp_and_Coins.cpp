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
        if(n%3 == 0){
            cout << n/3 << " " << n/3 << endl;
        }
        else if(n%3 == 1){
            cout << n/3 +1 << " " << n/3 << endl;
        }
        else{
            cout << n/3 << " " << n/3+1 << endl;
        }
    }
    return 0;
}