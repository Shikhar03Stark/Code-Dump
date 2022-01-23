// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

void solve(){
    int c;
    cin >> c;
    map<string, int> likes, dislikes;
    pair<string, int> p;
    set<string> toppings;
    for(int i = 0; i<c; i++){
        int nlikes;
        cin >> nlikes;
        for(int j = 0; j<nlikes; j++){
            string top;
            cin >> top;
            toppings.insert(top);
            likes[top]++;
        }
        int ndis;
        cin >> ndis;
        for(int j = 0; j<ndis; j++){
            string top;
            cin >> top;
            toppings.insert(top);
            dislikes[top]++;
        }
    }
    //vector<int> arr;
    //auto
    //pair<T,U>
    //map<T,U>
    for(auto& p: toppings){
        //cout << p << nl;
        likes[p]++;
        dislikes[p]++;
    }
    //cout << nl;
    map<string, double> ratio;
    for(auto& t: toppings){
        ratio[t] = ((double)likes[t])/(dislikes[t]);
        //cout << t << " " << ratio[t] << nl;
    }

    int ntops = toppings.size();
    //trial and error : logic
    int k = ntops/2;
    vector<pair<double, string>> acceptance;
    for(auto& r: ratio){
        acceptance.push_back({r.second, r.first});
    }
    //cout << nl;
    sort(acceptance.begin(), acceptance.end());
    for(auto& a: acceptance){
        //cou << a.first << " " << a.second << nl;
    }

    vector<string> ans;
    for(int i = ntops - k; i<ntops; i++){
        ans.push_back(acceptance[i].second);
    }

    cout << ans.size() << " ";
    for(auto& t: ans){
        cout << t << " ";
    }
    cout << nl;



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