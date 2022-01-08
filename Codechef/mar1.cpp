#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int c;
        cin >> c;
        int d = 0, t = c;
        while(t > 0){
            d++;
            t = (t>>1);
        }
        int lim = (int)pow(2,d);
        int a = lim/2;
        int other = c ^ a;
        while(other < 0 || other >= lim){
            a = a-1;
            other = c^a;
        }

        int mult = a*other;
        while(a>0){
            int x = a-1;
            int y = c^x;
            if(y >= lim){
                break;
            }
            if(x*y > mult){
                mult = x*y;
                a = x;
            }
            else{
                break;
            }
        }

        cout << mult << endl;

    }
    return 0;
}