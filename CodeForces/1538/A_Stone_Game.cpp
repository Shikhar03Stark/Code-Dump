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
        for(auto& e : arr){
            cin >> e;
        }

        int mini = min_element(begin(arr), end(arr)) - begin(arr);
        int maxi = max_element(begin(arr), end(arr)) - begin(arr);

        if(maxi < mini){
            swap(mini, maxi);
        }

        int ans = n;
        ans = min(ans, maxi+1);
        ans = min(ans, mini+1 + n-maxi);
        ans = min(ans, n-mini);
        cout << ans << endl;
        /*
        if(mini == maxi){
            cout << min(mini+1, n-mini) << endl;
        }

        else if(mini <= n/2 && maxi <= n/2){
            cout << max(maxi, mini) +1 << endl;
        }

        else if(mini > n/2 && maxi > n/2){
            cout << n - min(mini, maxi) << endl;
        }

        else{
            cout << min(mini+1, n-mini) + min(maxi+1, n-maxi) << endl;
        }*/
        

    }
    return 0;
}