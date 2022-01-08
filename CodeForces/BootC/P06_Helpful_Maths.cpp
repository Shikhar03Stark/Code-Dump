// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

int solve(){
    string s;
    cin >> s;
    bool digit = true;
    int n = s.size();
    vector<int> nums;
    for(int i = 0; i<n; i++){
        if(digit){
            nums.push_back(s[i]-'0');
        }
        digit = !digit;
    }
    sort(nums.begin(), nums.end());
    n = nums.size();
    for(int i = 0; i<n; i++){
        if(i == n-1){
            cout << nums[i] << nl;
        }
        else{
            cout << nums[i] << '+';
        }
    }
    return 0;
}

int main(){
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}