#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

string bt(string &s, int idx, vector<bool> &vis, string ans){
    int n = s.size();
    if(idx >= n){
        for(int i = 0; i<n; i++){
            if(s[i] == ans[i]){
                return "";
            }
        }
        return ans;
    }
    else{
        for(int i = 0; i<n; i++){
            if(!vis[i] && s[i] != s[idx]){
                vis[i] = true;
                ans.push_back(s[i]);
                string branch = bt(s, idx+1, vis, ans);
                if(branch != ""){
                    return branch;
                }
                ans.pop_back();
                vis[i] = false;
            }
        }

        return "";
    }
}

int main(){
    int t;
    cin>>t;
    for(int z = 1; z<=t; z++){
        cout << "Case #" << z << ": ";
        string s;
        cin >> s;
        int n = s.size();
        unordered_map<char, int> h;
        for(int i = 0; i<n; i++){
            h[s[i]]++;
        }

        auto comp = [&h](char a, char b)->bool{
            return h[a] <= h[b];
        };
        priority_queue<char, vector<char>, decltype(comp)> pq(comp);
        for(auto &p: h){
            pq.push(p.first);
        }

        stack<char> S;
        int idx = 0;
        string ans;
        while(!pq.empty()){
            char c = s[idx];
            while(!pq.empty() && pq.top() == c){
                S.push(pq.top());
                pq.pop();
            }
            char top = 0;
            if(!pq.empty()){
                top = pq.top(); pq.pop();
                ans.push_back(top);
            }
            if(top == 0){
                break;
            }
            h[top]--;
            if(h[top] > 0){
                pq.push(top);
            }
            while(!S.empty()){
                pq.push(S.top());
                S.pop();
            }
            idx++;
        }

        if(ans.size() == n){
            cout << ans << endl;
        }
        else{
            cout << "IMPOSSIBLE" << endl;
        }

    }
    return 0;
}