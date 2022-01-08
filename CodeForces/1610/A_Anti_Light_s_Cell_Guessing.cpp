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
        if(x==1 && y == 1){
            cout << 0 << endl;
        }
        else{
            int mi = min(x, y);
            cout << (mi>1?2:1) << endl;
        }
    }
    return 0;
}