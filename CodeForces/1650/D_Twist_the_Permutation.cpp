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

bool lrotate(vector<int> &arr, int n, int x){
    vector<int> aux(n);
    for(int i = 0; i<n; i++){
        aux[(i-x+n)%n] = arr[i];
    }
    for(int i = 0; i<n; i++){
        arr[i] = aux[i];
    }
    return true;
}

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    int disp = 0;
    map<int,int> idx;
    for(int i = 0; i<n; i++){
        cin >> arr[i];
        idx[arr[i]] = i;
    }
    vector<int> ans;
    for(int i = n-1; i>=0; i--){
        bool f = false;
        for(int j = i-1; j>=0; j--){
            if(arr[j]==i+1){
                f=true;
                ans.push_back(j+1);
                lrotate(arr, i+1, j+1);
                break;
            }
        }
        if(!f){
            ans.push_back(0);
        }
    }
    for(auto e: vector<int>(ans.rbegin(), ans.rend())){
        cout << e << " ";
    }
    cout << nl;

    return;
}

int main(){
    FASTIO
    pre();
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}