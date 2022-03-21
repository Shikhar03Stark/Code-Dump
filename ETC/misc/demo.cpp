// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

void pre(){
    
    return;
}

void closestNumbers(vector<int> numbers){
    sort(numbers.begin(), numbers.end());
    map<int, vector<pair<int,int>>> h;
    int n = numbers.size();
    int mindiff = INT_MAX;
    for(int i = 1; i<n; i++){
        int diff = numbers[i] - numbers[i-1];
        mindiff = min(mindiff, diff);
        h[diff].push_back({numbers[i-1], numbers[i]});
    }

    vector<pair<int,int>> ans = h[mindiff];
    sort(ans.begin(), ans.end());
    for(auto& e: ans){
        cout << e.first << " " << e.second << endl;
    }

}

int deleteProducts(vector<int> ids, int m){
    int n = ids.size();
    map<int,int> h;
    for(int i = 0; i<n; i++){
        h[ids[i]]++;
    }
    vector<pair<int,int>> p;
    for(auto& e: h){
        p.push_back({e.second, e.first});
    }
    sort(p.begin(), p.end());
    for(int i = 0; i<p.size(); i++){
        cout << p[i].first << " " << p[i].second << nl;
        int val = p[i].first;
        if(val > m){
            return p.size()-i;
        }
        else{
            m -= val;
        }
    }
    return 0;
}

vector<int> solve(int X, vector<int> arr, vector<int> query_values){
    int n = arr.size();
    map<int,vector<int>> h;
    for(int i = 0; i<n; i++){
        h[arr[i]].push_back(i+1);
    }
    vector<int> ans;
    for(auto& q: query_values){
        if(q>n){
            ans.push_back(-1);
        }
        else{
            ans.push_back(h[X][q-1]);
        }
    }
    return ans;
}

void solve(){
    // cout << deleteProducts({1,1,1,2,3,2}, 2) << nl;
    cout << 
    return;
}

int main(){
    FASTIO
    pre();
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}