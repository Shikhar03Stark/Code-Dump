#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

const ull bck11 = 15709090909091;
const ull mod = 12*60*60* (ull)1e9;

bool solve(ull a, ull b, ull c) {

    ull t = (((b-a) * bck11) % mod + mod) % mod;

    if ((708 * t - c + b) % mod == 0) {

        ll n = t % (ll)1e9;

        t /= 1e9;

        ll s = t % 60;

        t /= 60;

        ll m = t % 60;

        ll h = t / 60;

        cout << h << " " << m << " " << s << " " << n << "\n";

        return true;

    }

    else return false;

}


int main(){
    int t;
    cin>>t;
    for(int z = 1; z<=t; z++){
        cout << "Case #" << z << ": ";
        ull a, b, c;
        if(solve(a, b, c)){

        }
        else if(solve(a, c, b)){

        }
        else if(solve(b, a, c)){

        }
        else if(solve(b, c, a)){

        }
        else if(solve(c, a, b)){

        }
        else if(solve(c, b, a)){

        }
        
    }
    return 0;
}