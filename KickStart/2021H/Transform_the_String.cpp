#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int z = 1; z<=t; z++){
        cout << "Case #" << z << ": ";
        string s, t;
        cin >> s;
        cin >>t;
        ll cost = 0;
        for(int i = 0; i<s.size();i++){
            ll dist = 30;
            for(int j = 0; j<t.size(); j++){
                dist = min({dist, (ll)abs(s[i]-t[j]), 26-(ll)abs(s[i]-t[j])});
            }
            cost += dist;
        }
        cout << cost << endl;
    }
    return 0;
}