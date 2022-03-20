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

void solve(){
    closestNumbers({6, 2, 4, 10});
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