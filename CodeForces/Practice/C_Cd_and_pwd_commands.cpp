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
    int n;
    cin >> n;
    vector<string> dir;
    for(int c = 0; c<n; c++){
        string cmd;
        cin >> cmd;
        if(cmd == "pwd"){
            if(dir.size()==0){
                cout << '/' << nl;
            }
            else{
                cout << '/';
                for(auto& e: dir){
                    cout << e << '/';
                }
                cout << nl;
            }
        }
        else{
            string path;
            cin >> path;
            if(path[0] == '/'){
                //abs
                vector<string> newdir;
                string s;
                for(int i = 1; i<path.size(); i++){
                    if(path[i] == '/'){
                        if(s==".."){
                            newdir.pop_back();
                            s = "";
                        }
                        else{
                            newdir.push_back(s);
                            s = "";
                        }
                    }
                    else{
                        s.push_back(path[i]);
                    }
                }
                if(s.size()>0){
                    if(s==".."){
                        newdir.pop_back();
                        s = "";
                    }
                    else{
                        newdir.push_back(s);
                        s = "";
                    }
                }

                dir = newdir;
            }
            else{
                //relative
                string s;
                for(int i = 0; i<path.size(); i++){
                    if(path[i] == '/'){
                        if(s==".."){
                            dir.pop_back();
                            s = "";
                        }
                        else{
                            dir.push_back(s);
                            s = "";
                        }
                    }
                    else{
                        s.push_back(path[i]);
                    }
                }
                if(s.size()>0){
                    if(s==".."){
                        dir.pop_back();
                        s = "";
                    }
                    else{
                        dir.push_back(s);
                        s = "";
                    }
                }

            }
        }
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