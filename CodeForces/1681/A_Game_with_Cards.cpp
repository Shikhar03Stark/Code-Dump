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

bool fWin(vector<int> &a, vector<int> &b){
    int n = a.size(), m = b.size();
    int top = -1;
    int i = n-1, j = m-1;;
    bool turn_a = true;
    while(true){
        if(turn_a){
            if(i<0) break;
            if(a[i] <= top){
                return false;
            }
            else{
                top = a[i];
                i--;
            }
        }
        else{
            if(j<0) break;
            if(b[j] <= top){
                return true;
            }
            else{
                top = b[j];
                j--;
            }
        }
        turn_a = !turn_a;
    }

    if(i<0) return false;
    return true;
    
}

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto& e: a){
        cin >> e;
    }
    int m;
    cin >> m;
    vector<int> b(m);
    for(auto& e: b){
        cin >> e;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    cout << (fWin(a, b)?"Alice":"Bob") << nl;
    cout << (fWin(b, a)?"Bob":"Alice") << nl;

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