// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

void solve(){
    string s;
    cin >> s;
    int n = 27;
    int l, r;
    for(char c = 'A'; c<='Z'; c++){
        for(int i = 0; i<n; i++){
            if(s[i] == c){
                r = i;
            }
            if(s[n-i-1] == c){
                l = n-i-1;
            }
        }
        if(l!=r){
            break;
        }
    }

    cerr << s[l] << " " << l << " " << r << nl;
    if(r-l<=1){
        cout << "Impossible" << nl;
        return;
    }
    int mid = l+(r-l-1)/2;
    vector<vector<char>> grid(2, vector<char>(13));
    int k = mid;
    for(int i = 0; i<13 && k>=0; i++){
        grid[0][i] = s[k--];
    }
    if(mid>=0){
        for(int i = 12; i>=0 && k>=0; i--){
            grid[1][i] = s[k--];
        }
    }
    k = mid+1;
    for(int i = 0; i<13 && k<27; i++){
        if(s[k] != s[l]){
            grid[1][i] = s[k++];
        }
        else{
            i--;
            k++;
        }
    }
    if(k<27){
        for(int i = 12; i>=0 && k<27; i--){
            if(s[k] != s[l]){
                grid[0][i] = s[k++];
            }
            else{
                i++;
                k++;
            }
        }
    }
    for(auto& row: grid){
        for(auto& e: row){
            cout << e;
        }
        cout << nl;
    }
    return;
}

int main(){
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}