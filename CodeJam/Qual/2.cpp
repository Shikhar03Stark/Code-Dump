#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

int main(){
    int t;
    cin>>t;
    for(int z = 1; z<=t; z++){
        cout << "Case #" << z << ": ";
        int x, y;
        string s;
        cin >> x >> y >> s;
        int n = s.size();
        int cost = 0;
        //start
        int wl = 0, wr = 1;
        while(wr<n){
            if(s[wr] == '?'){
                wr++;
            }
            else{
                if(s[wl] != '?' && s[wl] != s[wr]){
                    if(s[wl] < s[wr]){ //CJ
                        cost += x;
                    }
                    else{
                        cost += y;
                    }
                }
                wl = wr++;
            }
        }

        cout << cost << endl;

        
    }
    return 0;
}