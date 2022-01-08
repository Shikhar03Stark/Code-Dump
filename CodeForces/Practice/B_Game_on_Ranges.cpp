// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<tuple<int,int,int>> arr(n);
    for(int i = 0; i<n; i++){
        int l, r;
        cin >> l >> r;
        arr[i] = {r-l, l, r};
    }
    sort(arr.begin(), arr.end());

    set<int> nums;
    //map<pair<int,int>, int> h;
    for(auto& t: arr){
        int l = get<1>(t), r = get<2>(t);
        int ans = l;
        while(nums.find(ans) != nums.end()){
            ans++;
        }
        nums.insert(ans);
        cout << l << " " << r << " " << ans << nl;
    }
    return;
}

int main(){
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}