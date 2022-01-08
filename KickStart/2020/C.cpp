#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

int main(){
    int t;
    cin>>t;
    for(int z = 1; z<=t; z++){
        cout << "Case #" << z << ": ";
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for(auto& e : arr){
            cin >> e;
        }
        vector<int> diff(n, 0);
        for(int i = 1; i<n; i++){
            diff[i] = arr[i] - arr[i-1];
        }

        priority_queue<int> pq;
        for(int i = 0; i<n; i++){
            pq.push(diff[i]);
        }
        //cerr << pq.top() << endl;
        while(pq.top() >= 1 && k>0){
            int m = pq.top();
            pq.pop();
            pq.push(m/2);
            pq.push(m - m/2);
            --k;
        }

        cout << ((pq.top() == 0)?1:pq.top()) << endl;
    }
    return 0;
}