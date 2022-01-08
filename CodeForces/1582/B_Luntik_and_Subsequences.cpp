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
        vector<int> cnt(2,0);
        for(auto&e:arr){
            cin >> e;
            if(e==0||e==1){
                cnt[e]++;
            }
        }
        cout << (ll)(cnt[1]*pow(2,cnt[0])) << endl;

    }
    return 0;
}