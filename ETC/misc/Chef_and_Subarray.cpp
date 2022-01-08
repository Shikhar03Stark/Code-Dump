#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto&e:arr){
        cin >> e;
    }
    int ans = 0;
    int left = 0, right=0;
    while(right<n){
        if(arr[right] == 0){
            ans = max(right-left, ans);
            left = right+1;
        }
        right++;
    }
    ans = max(ans, right-left);
    cout << ans << endl;
    return 0;
}