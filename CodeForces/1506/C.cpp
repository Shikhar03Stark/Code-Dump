#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s1, s2;
        cin >> s1;
        cin >> s2;
        map<string, int> h;
        if(s1.size() < s2.size()){
            swap(s1, s2);
        }
        h[s1] = 0;
        for(int w = 1;w<=s1.size(); w++){
            for(int i = w; i<=s1.size(); i++){
                h[s1.substr(i-w, w)] = i-w;

            }
        }
        if(h.count(s2) > 0){
            cout << s1.size() - s2.size() << endl;
        }
        else{
            bool found = false;
            for(int w = s2.size()-1;w>0;w--){
                for(int i = w; i<=s2.size(); i++){
                    if(h.count(s2.substr(i-w, w)) > 0){
                        string f = s2.substr(i-w, w);
                        int ops = 0;
                        ops += max(0, h[f]);
                        ops += max(0, int(s1.size() - h[f] - w));
                        ops += max(0, i-w);
                        ops += max(0, int(s2.size()-i));
                        cout << ops << endl;
                        found = true;
                    }
                    if(found)
                        break;
                }
                if(found)
                    break;
            }

            if(!found){
                cout << s1.size() + s2.size() << endl;
            }

        }
    }
    return 0;
}