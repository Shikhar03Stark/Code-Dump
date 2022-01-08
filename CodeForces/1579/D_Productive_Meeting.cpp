#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

struct person{
    int index, soc;
};

bool comp(person a, person b){
    return a.soc <= b.soc;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        vector<person> arr(n);
        priority_queue<pair<int,int>> pq;
        for(int i = 0; i<n; i++){
            int a;
            cin >> a;
            if(a > 0)
                pq.push({a, i+1});
        }

        vector<vector<int>> ans;
        while(pq.size() > 1){
            auto x = pq.top(); pq.pop();
            auto y = pq.top(); pq.pop();
            ans.push_back({x.second, y.second});
            if(--x.first){
                pq.push({x.first, x.second});
            }
            if(--y.first){
                pq.push({y.first, y.second});
            }
        }

        cout << ans.size() << endl;
        for(auto& e: ans){
            cout << e[0] << " " << e[1] << endl;
        }

    }
    return 0;
}