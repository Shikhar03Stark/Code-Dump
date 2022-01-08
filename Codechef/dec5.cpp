#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

unsigned int intLog2(unsigned int x){
    uint res = 0;
    while( x = x>>1 ){
        ++res;
    }

    return res;
}

uint raise2(uint x){
    uint res = 1;
    while(x--){
        res <<= 1;
    }
    return res;
}

int minIndex(vector<uint> &v, int start){
    uint val = 1;
    int min = start+1;
    for(int i = start+1; i<v.size(); i++){
        if(v[i] >= val && v[min] > v[i]){
            min = i;
        }
    }

    return min;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n, x, left=0;
        cin >> n >> x;
        vector<ll> seq(n);
        for(ll &e : seq){
            cin >> e;
        }
        int i=0;
        ll ops = x;
        for(;ops>0 && i<n-1; ops--){
            int p = intLog2(seq[i]);
            bool isFound = false;
            seq[i] ^= 1<<p;
            for(int j = i+1; j<n;j++){
                if(seq[j]^(1<<p) < seq[j]){
                    isFound = true;
                    seq[j] ^= 1<<p;
                    break;
                }
            }
            if(!isFound){
                seq[n-1] ^= 1<<p;
            }

            while(seq[i] <= 0){
                i++;
            }
            left = ops + 1;
        }
        if(left>0){
            if((n<3) && left%2>0){
                seq[n-1] ^= 1;
                seq[n-2] ^= 1;
            }
        }

        for(auto &e : seq){
            cout << e << " ";
        }
        cout << endl;

    }
    return 0;
}