#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        vector<int> univ(n), skill(n);
        for(auto& i : univ){
            cin >> i;
        }
        for(auto& i : skill){
            cin >> i;
        }
        unordered_map<int, vector<ull>> mp;
        set<int> u;
        for(int i = 0;i<n; i++){
            mp[univ[i]].push_back(skill[i]);
            u.insert(univ[i]);
        }

        for(auto& p : mp){
            sort(p.second.begin(), p.second.end(), greater<int>());
            for(int i = 1; i<p.second.size(); i++){
                p.second[i] += p.second[i-1];
            }
        }

        for(int k = 1; k<=n; k++){
            ull sum = 0;
            for(auto& p : mp){
                int inc = (p.second.size()/k) * k;
                if(inc>0){
                    sum += p.second[inc-1];
                }
            }
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}