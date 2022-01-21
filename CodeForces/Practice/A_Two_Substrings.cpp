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
    int n = s.size();
    vector<int> posa, posb;
    for(int i = 1; i<n; i++){
        string a = s.substr(i-1,2);
        if(a=="AB"){
            posa.push_back(i);
        }
        if(a=="BA"){
            posb.push_back(i);
        }
    }
    for(auto& e: posa){
        cerr << e << " ";
    }
    cerr << nl;
    for(auto& e: posb){
        cerr << e << " ";
    }
    cerr << nl;
    bool diff = false;
    for(int i = 0; i<posa.size(); i++){
        int lb = lower_bound(posb.begin(), posb.end(), posa[i]+2) - posb.begin();
        if(lb!=posb.size()){
            cout << "YES" << nl;
            return;
        }
        int lt = upper_bound(posb.begin(), posb.end(), posa[i]-2) - posb.begin();
        if(lt != 0 && abs(posb[lt-1] - posa[i]) > 1){
            cout << "YES" << nl;
            return;
        }
    }
    cout << "NO" << nl;

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