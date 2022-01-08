#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

bool possible(string &s, ll start, ll a, ll b, ll p){
    ll cost = 0;
    int n = s.size();
    char prev = s[start];
    for(int i = start+1; i<n-1; i++){
        if(prev == 'A' && s[i] == 'B'){
            cost += a;
        }
        if(prev == 'B' && s[i] == 'A'){
            cost += b;
        }
        prev = s[i];
    }

    if(prev=='A') cost += a;
    if(prev=='B') cost += b;
    return cost<=p;
}

int solve(){
    ll a, b, p;
    cin >> a >> b >> p;
    string s;
    cin >> s;
    int n = s.size();
    ll low = 0, high = n-1;
    while(low<=high){
        ll mid = (low+high)/2;
        if(possible(s, mid, a, b, p)){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    if(low==n){
        cout << n << endl;
        return 0;
    }
    cout << low+1 << endl;
    return 0;
}

int main(){
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}