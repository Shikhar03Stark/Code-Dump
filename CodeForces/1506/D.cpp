#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(auto &e: arr){
            cin >> e;
        }
        map<int, int> freq;
        for(auto& e:arr){
            freq[e]++;
        }
        auto comp  = [&](int a, int b) -> bool{
            return freq[a] < freq[b];
        };
        priority_queue<int, vector<int>, decltype(comp)> pq(comp);
        for(auto& e: freq){
            pq.push(e.first);
        }
        int cnt = 0;
        while(pq.size() > 1){
            int t = pq.top();
            pq.pop();
            int t2 = pq.top();
            pq.pop();
            freq[t] = freq[t] - freq[t2];
            if(freq[t] > 0){
                pq.push(t);
            }
        }

        if(pq.empty()){
            cout << 0 << endl;
        }
        else{
            cout << freq[pq.top()] << endl;
        }
    }
    return 0;
}