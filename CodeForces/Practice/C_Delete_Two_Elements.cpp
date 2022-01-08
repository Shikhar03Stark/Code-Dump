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
        vector<int> arr(n);
        ll sum = 0;
        for(int i = 0; i<n; i++){
            cin >> arr[i];
            sum += (ll)arr[i];
        }
        if((2*sum)%n == 0){
            ll t = 2*sum/n;
            map<int,int> h;
            ll cnt = 0;
            for(int i = 0; i<n; i++){
                ll left = t-arr[i];
                cnt += h[left];
                h[arr[i]]++;
            }
            cout << cnt << endl;
        }
        else{
            cout << 0 << endl;
        }

    }
    return 0;
}