#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for(auto& e: arr){
        cin >> e;
    }
    priority_queue<int> pq;
    ll sum = 0;
    for(int i = 0; i<n; i++){
        sum += arr[i];
        if(sum <= m){
            cout << 0 << " ";
        }
        else{
            int t = sum;
            stack<int> S;
            int cnt = 0;
            while(t>m && !pq.empty()){
                S.push(pq.top()); pq.pop();
                t -= S.top();
                cnt++;
            }
            cout << cnt << " ";
            while(!S.empty()){
                pq.push(S.top()); S.pop();
            }
        }
        pq.push(arr[i]);
    }
    return 0;
}