#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        unordered_map<string,set<char>> h;
        cin >> n;
        vector<string> words(n);
        vector<vector<string>> quick(26, vector<string>(0));
        set<char> firstLet;
        for(auto &s : words){
            cin >> s;
            //form group
            h[s.substr(1)].insert(s[0]);
        }

        int count = 0;
        vector<string> group;
        for(auto &str: h){
            group.push_back(str.first);
        }

        for(int i = 0; i<group.size()-1; i++){
            for(int j = i+1; j<group.size(); j++){
                int dup = 0;
                for(auto &c: h[group[i]]){
                    if(h[group[j]].find(c) != h[group[j]].end()){
                        //dupli exists
                        dup++;
                    }
                }
                count += (h[group[i]].size() - dup)*(h[group[j]].size() - dup);
            }
        }
        

        cout << 2*count << endl;

        

    }
    return 0;
}