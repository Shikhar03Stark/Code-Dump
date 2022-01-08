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
        int a, b, c;
        cin >> a >> b >> c;
        int ones = a - c +1;
        int x = 0;
        int gc = pow(10, c-1);
        for(int i = 0; i<ones; i++){
            x += pow(10,i);
        }
        x *= gc;
        int y = pow(10,b-1);
        cout << x << ' ' << y << endl;
    }
    return 0;
}