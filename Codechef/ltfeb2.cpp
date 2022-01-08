#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin >> s;
        if(s.size() == 1){
            cout << "NO" << endl;
            continue;
        }
        //sort(s.begin(), s.end());
        map<char,int> h;
        for(int  i =0; i<s.size(); i++){
            h[s[i]]++;
        }
        int evens = 0;
        int ones = 0;
        for(auto& p: h){
            if(p.second == 1){
                ones++;
            }
            if(p.second%2 == 0){
                evens++;
            }
        }
        if(ones == 0 || ones < evens){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}