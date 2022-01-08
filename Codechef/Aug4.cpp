#include <bits/stdc++.h>

typedef unsigned int ui;
typedef long int li;

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s, p;
        cin >> s >> p;

        for(const auto &c: p){
            s.erase(s.begin() + s.find(c));
        }

        sort(s.begin(), s.end());

        bool insert = false;

        string t;
        /*for(const auto &c: s){
            if(!insert && c <= p[0]){
                t.push_back(c);
            }
            else if(insert){
                t.push_back(c);
            }
            else{
                t += p;
                insert = true;
                t.push_back(c);
            }
        }*/
        for(int i = 0; i<s.size(); i++){
            if(s[i] > p[0]){
                t += p + s.substr(i);
                insert = true;
                break;
            }
            else{
                t.push_back(s[i]);
            }
        }

        if(!insert)
            t += p;

        cout << t << endl;
    }
    return 0;
}