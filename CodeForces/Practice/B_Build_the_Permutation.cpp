// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

void solve(){
    int n, a, b;
    cin >> n >> a >> b;
    if(abs(a-b)>1){
        cout << -1 << nl;
        return;
    }
    if(a+b>n-2){
        cout << -1 << nl;
        return;
    }
    vector<int> p(n,1);
    int minus = 0;
    bool aturn = true;
    for(int i = 1; i<n; i++){
        if(a+b==0){
            p[i] = p[i-1];
        }
        else if(i == 1){
            if(a>=b) p[i] = 1, aturn = true;
            else p[i] = -1, aturn = false;
        }
        else{
            p[i] = p[i-1]*-1;
            (aturn?a--:b--);
        }
        minus += (p[i]<0)?1:0;
    }
    
    int mid = minus+1;
    int low = mid-1, high = mid+1;
    p[0] = mid;
    for(int i = 1; i<n; i++){
        if(p[i]>0) p[i] = high++;
        if(p[i]<0) p[i] = low--;
    }
    for(auto& e: p){
        cout << e << " ";
    }
    cout << nl;
    return;
}

int main(){
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}