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
        int x, y;
        cin >> x >> y;
        if(y-x>0){
            if((y-x)%2 == 1){
                cout << (y-x)/2 + 2 << endl;
            }
            else{
                cout << (y-x)/2 << endl;
            }
        }
        else{
            cout << x-y << endl;
        }
    }
    return 0;
}