// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;
const int N = 2e3 + 10;
bool prime[N];
vector<int> p;
void pre(){
    for(int i = 2; i<N; i++){
        prime[i] = true;
    }
    for(int i = 2; i<N; i++){
        if(prime[i]){
            p.push_back(i);
            for(int j = 2*i; j<=i*i && j<N; j+=i){
                prime[j] = false;
            }
        }
    }
}

vector<int> pfactor(int n){
    vector<int> ans;
    for(int i = 2; i<=n; i++){
        if(n%i==0){
            ans.push_back(i);
            while(n%i==0){
                n /= i;
            }
        }
    }
    return ans;
}

void solve(){
    int n;
    cin >> n;
    int cnt = 0;
    for(int i = 1; i<=n; i++){
        vector<int> pf = pfactor(i);
        if(pf.size()==2){
            cnt++;
        }
    }
    cout << cnt << nl;
    return;
}

int main(){
    pre();
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}