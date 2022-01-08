#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int z = 1; z<=t; z++){
        cout << "Case #" << z << ": ";
        int n, k;
        cin >> n >>k;
        vector<int> ticket(n);
        for(auto& e : ticket){
            cin >> e;
        }
        sort(ticket.begin(), ticket.end());
        auto comp = [](pair<int,int> a, pair<int,int> b){
            return a.second-a.first < b.second - b.first;
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> pq(comp);
        //pq.push({1,ticket[0]});
        //pq.push({ticket[ticket.size()-1], k});

        for(int i = 0; i<ticket.size()-1; i++){
            pq.push({ticket[i], ticket[i+1]});
        }

        pair<int,int> m1 = pq.top(); pq.pop();
        pair<int,int> m2 = pq.empty()?make_pair(0,0):pq.top();
        cerr << m1.first << " " << m1.second << endl;
        cerr << m2.first << " " << m2.second << endl;
        ull cnt = 0;
        //m1
        vector<int> ans;
        ans.push_back((m1.second-m1.first)/2);
        ans.push_back((m2.second-m2.first)/2);
        if(ticket[0] != 1){
            ans.push_back(max(0,ticket[0]-1));
        }
        if(ticket[n-1] != k){
            ans.push_back(max(0,k-ticket[n-1]));
        }
        sort(begin(ans), end(ans), greater<int>());

        cerr << ans[0] << ", " << ans[1] << endl;

        cnt = ans[0]+ans[1];
        cout << (double)(cnt+0.0)/k << endl;
    }
    return 0;
}