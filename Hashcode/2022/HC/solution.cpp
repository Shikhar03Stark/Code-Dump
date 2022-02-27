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

void solve(){
    ll c, p;
    cin >> c >> p;
    map<string, vector<pair<string, ll>>> contrib;
    map<string, vector<pair<ll, string>>> sk;
    map<string, vector<ll>> proj_detail;
    map<string, vector<pair<string,ll>>> proj_req;

    for (int i = 0; i<c; i++){
        string name;
        cin >> name;
        ll skills;
        cin >> skills;
        for(int j = 0; j<skills; j++){
            string skill;
            cin >> skill;
            ll lvl;
            cin >> lvl;
            contrib[name].push_back({skill, lvl});
            sk[skill].push_back({lvl, name});
        }
    }

    for(auto& e: sk){
        sort(e.second.rbegin(), e.second.rend());
    }
    for(auto& e: sk){
        cerr << e.first << nl;
        for(auto& p: e.second){
            cerr << '(' << p.first << " " << p.second << ") ";
        }
        cerr << nl;
    }

    for(int i = 0; i<p; i++){
        string name;
        cin >> name;
        ll d, b, s, r;
        cin >> d >> b >> s >> r;
        proj_detail[name] = {d, b, s, r};
        for(int j = 0; j<r; j++){
            string skill;
            cin >> skill;
            ll lvl;
            cin >> lvl;
            proj_req[name].push_back({skill, lvl});
        }
    }

    auto sortby_days = [&](const string& a, const string& b){
        return proj_detail[a][0] < proj_detail[b][0];
    };

    auto sortby_score = [&](const string& a, const string& b){
        return proj_detail[a][1] < proj_detail[b][1];
    };

    auto sortby_bestbefore = [&](const string& a, const string& b){
        return proj_detail[a][2] < proj_detail[b][2];
    };

    auto sortby_numroles = [&](const string& a, const string& b){
        return proj_detail[a][3] < proj_detail[b][3];
    };

    auto sortby_scorebyreq = [&](const string& a, const string& b){
        return (0.0+proj_detail[a][1])/proj_detail[a][3] < (0.0+proj_detail[b][3])/proj_detail[b][3];
    };

    auto sortby_scorebyday = [&](const string& a, const string& b){
        return (0.0+proj_detail[a][1])/proj_detail[a][0] < (0.0+proj_detail[b][3])/proj_detail[b][0];
    };

    vector<string> proj_order;
    for(auto& e: proj_detail)    {
        proj_order.push_back(e.first);
    }

    sort(proj_order.rbegin(), proj_order.rend(), sortby_scorebyday);
    vector<pair<string, vector<string>>> ans;
    for(auto& s: proj_order){
        cerr << "PROJECT: " << s << nl;
        int roles = proj_detail[s][3];
        set<string> S;
        pair<string, vector<string>> elem = {s, vector<string>()};
        set<string> taken;
        bool pos = true;
        for(int i = 0; i<roles; i++){
            string skill = proj_req[s][i].first;
            ll lvl = proj_req[s][i].second;

            ll clist = sk[skill].size();
            for(int i = 0; i<clist; i++){
                if(sk[skill][i].first >= lvl && taken.find(sk[skill][i].second) == taken.end()){
                    elem.second.push_back(sk[skill][i].second);
                    taken.insert(sk[skill][i].second);
                    break;
                }
                else if(sk[skill][i].first < lvl){
                    pos = false;
                    break;
                }
            }

        }
        if(elem.second.size() != roles) pos = false;
        if(pos){
            ans.push_back(elem);
        }

    }
    cout << ans.size() << nl;
    for(auto& e: ans){
        cout << e.first << nl;
        for(auto& name: e.second){
            cout << name << " ";
        }
        cout << nl;
    }
    return;
}

int main(){
    FASTIO
    pre();
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}