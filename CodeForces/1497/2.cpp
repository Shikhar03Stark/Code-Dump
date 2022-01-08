#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for(auto& e : arr){
            cin >> e;
        }
        if(k == 1){
            cout << 1 << endl;
            continue;
        }
        unordered_map<int, int> freq;
        for(int i = 0; i<n; i++){
            freq[arr[i]%k]++;
        }
        int ans = 0;
        for(int i = 1; i<=(k)/2; i++){
            int req = k - i;
            if(freq[req] == freq[i] && freq[req] != 0){
                ans++;
            }
            else{
                int left = max(freq[i], freq[req]) - min(freq[i], freq[req]);
                ans += left;
            }
        }
        if(freq[0] > 0){
            ans++;
        }

        cout << ans << endl;

    }
    return 0;
}