#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

pair<char,char> findp(string &s, string &p){
    int i = 0, j = 0;
    for(;i<s.size() && j<p.size(); i++, j++){
        if(s[i] != p[j]){
            return {s[i], p[j]};
        }
    }
    if(s.size() > p.size()) return {-1,-1};
    return {0,0};
}

bool topsort(vector<set<int>> &gp, vector<char> &order, set<char> &S){
    vector<int> deg(26,0);
    for(int i = 0; i<26; i++){
        for(auto& next: gp[i]){
            deg[next]++;
        }
    }

    queue<int> Q;
    for(int i = 0; i<26; i++){
        if(deg[i] == 0) Q.push(i);
    }
    vector<bool> vis(26);
    while(!Q.empty()){
        int node = Q.front(); Q.pop();
        vis[node] = true;
        order.push_back(node+'a');
        for(auto& next: gp[node]){
            deg[next]--;
            if(deg[next] == 0 && vis[next] == 0){
                Q.push(next);
            }
        }
    }
    if(order.size() < 26){
        return false;
    }
    return true;
}

int solve(){
    int n;
    cin >> n;
    vector<string> arr(n);
    for(int i = 0; i<n; i++){
        string s;
        cin >> s;
        arr[i] = s;
    }

    vector<set<int>> gp(26);
    set<char> S;
    for(int i = 1; i<n; i++){
        pair<char,char> p = findp(arr[i-1], arr[i]);
        if(p.first == -1){
            cout << "Impossible" << endl;
            return 0;
        }
        if(p.first != 0){
            gp[p.first-'a'].insert(p.second-'a');
            S.insert(p.first);
            S.insert(p.second);
        }
    }

    vector<char> order;
    bool possible = topsort(gp, order, S);
    if(possible){
        for(int i = 0; i<26; i++){
            cout << order[i];
        }
        cout << endl;
        return 0;
    }
    cout << "Impossible" << endl;
    return 0;
}

int main(){
    solve();
    return 0;
}