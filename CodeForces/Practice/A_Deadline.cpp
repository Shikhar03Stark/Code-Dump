#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

int solve(){
    int n, d;
    cin >> n >> d;
    if(d <= n){
        cout << "YES" << endl;
    }
    else{
        int low = 0, high = n-1;
        bool pos = false;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(n-(mid+ceil(d/(mid+1.0))) >= 0){
                //cout << "YES" << endl;
                pos = true;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        if(pos){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}