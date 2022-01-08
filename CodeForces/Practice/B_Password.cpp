#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

int solve(){
    string s;
    cin >> s;
    int n = s.size();
    vector<int> p(n,0);
    int left = 0;
    int len = 0;
    for(int i = 1; i<n; i++){
        int j = p[i-1];
        while(j>0 && s[j] != s[i]){
            j = p[j-1];
        }
        if(s[i] == s[j]){
            p[i] = j+1;
        }
        else{
            p[i]=0;
        }
    }
    for(auto& e: p){
        cerr << e << " ";
    }
    cerr << endl;
    if(p[n-1]>0){
        for(int i = 0; i<n-1; i++){
            if(p[i] == p[n-1]){
                cout <<s.substr(0,p[n-1])<< endl;
                return 0;
            }
        }
        if(p[p[n-1]-1] != 0){
            cout << s.substr(0, p[p[n-1]-1]) << endl;
        }
        else{
            cout << "Just a legend" << endl;
        }
    }
    else{
        cout << "Just a legend" << endl;
    }
    return 0;
}

int main(){
    FASTIO
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}