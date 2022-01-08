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
        int n, q;
        cin >> n >> q;
        vector<int> len(n);
        for(auto& e: len){
            cin >> e;
        }
        vector<int> que(q);
        for(auto& e: que){
            cin >> e;
        }

        sort(len.begin(), len.end());
        unordered_map<int, int> h;
        vector<int> arr;
        h[len[0]] = n;
        arr.push_back(len[0]);
        for(int i = 1; i<n; i++){
            int new_len = len[i] + i;
            int mini = new_len;
            //cerr << "MINI " << mini << "\n";
            if(i != n-1){
                mini = min(new_len, len[i+1]);
            }
            if(h.count(mini) == 0){
                h[mini] = n-i;
                arr.push_back(mini);
            }
        }

        for(auto& k: que){
            int n = arr.size();
            int idx = lower_bound(arr.begin(), arr.end(), k) - arr.begin();
            if(idx == n){
                cout << 0 << endl;
            }
            else{
                cout << h[arr[idx]] << endl;
            }
        }
    }
    return 0;
}