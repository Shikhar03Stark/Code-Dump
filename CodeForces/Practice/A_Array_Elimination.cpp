// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

vector<int> divisors(int n){
    if(n>0){
        vector<int> ans;
        for(int i = 1; i*i<=n; i++){
            if(n%i==0){
                if(i!=n/i){
                    ans.push_back(i);
                    ans.push_back(n/i);
                }
                else{
                    ans.push_back(i);
                }
            }
        }
        return ans;
    }
    return {};
}

void solve(){
    int n;
    cin >> n;
    vector<int> bits(32, 0);
    for(int i = 0; i<n; i++){
        int num;
        cin >> num;
        for(int i = 0; i<=30; i++){
            bits[i] += ((num&(1<<i))>0)?1:0;
        }
    }
    int g = 0;
    for(int i = 0; i<=30; i++){
        if(bits[i]>0){
            if(g==0){
                g = bits[i];
            }
            else{
                g = __gcd(g, bits[i]);
            }
        }
    }
    if(g==0){
        for(int i = 1; i<=n; i++){
            cout << i << " ";
        }
        cout << nl;
    }
    else{
        vector<int> divs = divisors(g);
        sort(divs.begin(), divs.end());
        for(auto& e: divs){ \
            cout << e << " ";
        }
        cout << nl;
    }
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