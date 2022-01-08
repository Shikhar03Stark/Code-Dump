#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, u, r, d, l;
        cin >> n >> u >> r >> d >> l;
        bool possible = false;
        for(int i = 0; i<16; i++){
            bitset<4> corners = i;
            //up
            {
                int count = corners[0] + corners[1];
                if(u-count > n-2 || count > u){
                    continue;
                }
            }
            //right
            {
                int count = corners[1] + corners[2];
                if(r - count > n-2 || count > r){
                    continue;
                }
            }
            //down
            {
                int count  = corners[2] + corners[3];
                if(d - count > n-2 || count > d){
                    continue;
                }
            }
            //left
            {
                int count = corners[3] + corners[0];
                if(l - count > n-2 || count > l){
                    continue;
                }
            }
            possible = true;
            break;
        }

        if(possible){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}