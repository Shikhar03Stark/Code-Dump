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
        string p, h;
        cin >> p >> h;
        if(h.size()<p.size()){
            cout << "NO" << endl;
            continue;
        }
        sort(p.begin(), p.end());
        map<char,int> mp;
        //bool found = false;
        for(int i =0 ;i<p.size(); i++){
            mp[p[i]]++;
        }
        int left = 0, right = h.size()-1;
        bool found = false;
        for(int i = 0; i+p.size()<=h.size(); i++){
            //string aux = h.substr(i, p.size());
            map<char,int> mpa;
            for(int j = i; j<i+p.size(); j++){
                mpa[h[j]]++;
            }
            bool match = true;
            for(int k = 0; k<p.size(); k++){
                if(mpa[p[k]] != mp[p[k]]){
                    match = false;
                    break;
                }
            }
            if(match){
                found = true;
                break;
            }
        }
        cout << (found?"YES":"NO") << endl;
    }
    return 0;
}