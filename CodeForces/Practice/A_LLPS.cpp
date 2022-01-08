#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

void solve(string &s, int left, int right, string palin, vector<string> &arr){
    if(left>right){
        if (palin.size()>0){
            arr.push_back(palin);
        }
        return;
    }
    if(s[left] == s[right]){
        string mid;
        if(left==right){
            mid = string(1, s[left]);
        }
        else{
            mid = string(2, s[left]);
        }
        solve(s, left+1, right-1, mid, arr);

        string aux = palin.substr(0, palin.size()/2) + mid + palin.substr(palin.size()/2);
        solve(s, left+1, right-1, aux, arr);

        solve(s, left+1, right-1, palin, arr);
        
    }
    else{
        solve(s, left+1, right, palin, arr);
        solve(s, left, right-1, palin, arr);
    }
}

int main(){
    string s;
    cin >> s;
    int n = s.size();
    vector<string> ans;
    solve(s, 0, s.size()-1, "", ans);
    sort(ans.rbegin(), ans.rend()); /*[](string a, string b){
        int an = a.size(), bn = b.size();
        int r = 0;
        for(r=0; r<min(an,bn); r++){
            if(a[r]>b[r]){
                return true;
            }
            else if(a[r]<b[r]){
                return false;
            }
        }
        if(an>=bn){
            return true;
        }
        return false;
    });*/
    cout << ans[0] << endl;
    return 0;
}