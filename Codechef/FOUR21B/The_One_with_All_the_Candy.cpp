#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

int solve(){
    ll n;
    cin >> n;
    vector<int> arr(n);
    for(auto& e: arr){
        cin >> e;
    }
    if(n==1){
        if(arr[0]>0){
            cout << 1 << endl;
        }
        else{
            cout << 0 << endl;
        }
        return 0;
    }
    ll mini = *min_element(arr.begin(), arr.end());
    ll ans = mini*n;
    for(auto& e: arr){
        e -= mini;
        cerr << e << " ";
    }
    cerr << endl;
    ll rem = 0;
    for(int i = 0; i<n; i++){
        if(arr[i] == 0){
            ll dist = 0;
            for(int j = 0; j<=n; j++){
                if(arr[i] == 0){
                    dist = 0;
                }
                else{
                    dist++;
                }
                rem = max(dist, rem);
                i = (n+i-1)%n;
            }
            break;
        }
    }

    cout << ans+rem << endl;
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