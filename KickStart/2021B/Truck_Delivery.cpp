#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

struct edge{
    int to;
    int limit;
    int64_t toll;
    
};

int calcGcd(vector<int64_t> arr){
    int64_t ans = arr[0];
    for(int i = 1; i<arr.size(); i++){
        ans = __gcd(ans, arr[i]);
    }
    return ans;
}

int solve(vector<vector<edge>>& list, vector<pair<int,int>>& que){
    vector<int> result;
    for(pair<int,int> q: que){
        int c = q.first;
        int w = q.second;

        vector<int> path;
        path.push_back(c);
        int target = 1;
        queue<vector<int>> Q;
        Q.push(path);
        vector<int> ans;
        while (true){
            vector<int> p = Q.front();
            Q.pop();
            if(p[p.size()-1] == target){
                ans = p;
                break;
            }
            int node = p[p.size()-1];
            for(edge e: list[node]){
                vector<int> newPath(p);
                newPath.push_back(e.to);
                Q.push(newPath);
            }
        }
        vector<int64_t> gcds;
        for(int i = 0; i<ans.size()-1; i++){
            for(int j = 0; j<list[ans[i]].size(); j++){
                if(list[ans[i]][j].to == ans[i+1]){
                    if(w >= list[ans[i]][j].limit){
                        gcds.push_back(list[ans[i]][j].toll);
                    }
                    break;
                }
            }
        }

        if(gcds.size() > 0){
            cout << calcGcd(gcds) << " ";
        }
        else{
            cout << 0 << " ";
        }

    }

    return 0;

}

int main(){
    int t;
    cin>>t;
    for(int z = 1; z<=t; z++){
        cout << "Case #" << z << ": ";
        int nodes, q;
        cin >> nodes >> q;
        vector<vector<edge>> list(nodes+1);
        for(int i = 0; i<nodes-1; i++){
            int x, y, l, t;
            cin >> x >> y >> l >> t;
            edge e;
            e.limit = l;
            e.toll = t;
            e.to = y;
            list[x].push_back(e);
            e.to = x;
            list[y].push_back(e);
        }
        vector<pair<int,int>> query(q);
        for(int i = 0; i<q; i++){
            cin >> query[i].first >> query[i].second;
        }

        int ans = solve(list, query);
        cout << endl;
    }
    return 0;
}