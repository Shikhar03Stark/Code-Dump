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
        ull n;
        cin >> n;
        int d = log10(n)+1;
        if(d <= 3){
            cout << -1 << endl;
        }
        else{
            int c = 0;
            int k = d-4;
            while(n>0){
                ull num = 2050 * pow(10,k);
               // cerr << n << " " << num << endl;
                if(n < 2050){
                    break;
                }
                if(num > n){
                    k--;
                }
                else{
                    n -= num;
                    c++;
                }
            }
            if(n == 0){
                cout << c << endl;
            }
            else{
                cout << -1 << endl;
            }
        }
    }
    return 0;
}