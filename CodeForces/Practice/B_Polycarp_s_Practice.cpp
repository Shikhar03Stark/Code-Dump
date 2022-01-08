#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

int solve(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    priority_queue<int> pq;
    for(int i = 0 ;i<n; i++){
        cin >> arr[i];
        pq.push(arr[i]);
    }
    vector<int> klar(k);
    int sum = 0;
    for(int i = 0; i<k; i++){
        klar[i] = pq.top(); pq.pop();
        sum += klar[i];
    }
    vector<bool> vis(n, false);
    for(int i = 0; i<k; i++){
        for(int j = 0; j<n; j++){
            if(arr[j] == klar[i] && vis[j] == false){
                vis[j] = true;
            }
        }
    }
    int prev = -1;
    int cnt = 0;
    vector<int> ans;
    for(int i = 0; i<n; i++){
        if(vis[i]==true && cnt<k){
            if(cnt==k-1)
                ans.push_back(n-1-prev);
            else
                ans.push_back(i-prev);
            prev = i;
            cnt++;
        }
    }
    cout << sum << endl;
    for(auto& e: ans){
        cout << e << " ";
    }
    cout << endl;

    return 0;
}

int main(){
    solve();
    return 0;
}