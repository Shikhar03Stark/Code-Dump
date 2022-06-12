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

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> arr;
    int i = 0;
    int ods = 0;
    while(i<n){
        int j = i;
        while(j+1<n && s[j+1] == s[i]) j++;
        arr.push_back(j-i+1);
        if((j-i+1)%2) ods++;
        i = j+1;
    }

    i = 0;
    int prev = -1;
    int cnt = 0;
    int sz = arr.size();
    while(i<sz){
        if(prev<0){
            if(arr[i]%2){
                prev = i;
            }
            else{
                i++;
            }
        }
        else{
            int j = i+1;
            while(j<sz && arr[j]%2==0) j++;
            cnt += j-i;
            i = j+1;
            prev = -1;
        }
    }
    // cout << cnt << nl;
    
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