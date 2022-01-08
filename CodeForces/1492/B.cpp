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
        vector<int> p(n);
        for(auto& pi : p){
            cin >> pi;
        }
        unordered_map<int, int> index;
        vector<int> ans;
        priority_queue<int> pq;
        for(auto pi: p){
            pq.push(pi);
        }
        for(int i = 0; i<n; i++){
            index[p[i]] = i;
        }

        int up = n-1;
        while(!pq.empty()){
            while(!pq.empty() && index[pq.top()] > up){
                pq.pop();
            }
            int top = pq.top();

            for(int i = index[top]; i<=up; i++){
                cout << p[i] << " ";
            }

            up = index[top]-1;
            if(!pq.empty())
                pq.pop();
        }
        cout << endl;

    }
    return 0;
}