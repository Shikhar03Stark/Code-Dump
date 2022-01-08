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
        string s,t;
        cin >> s;
        cin >> t;
        
        int n = s.size(), k = t.size();
        bool found = false;
        for(int i = 0; i<n; i++){
            if(s[i] == t[0]){
                int is = i, it = 0;
                while(it<k && is < n){
                    if(s[is] != t[it]){
                        break;
                    }
                    it++;
                    is++;
                }
                is -= 2;
                while(it<k && is >= 0){
                    if(s[is] != t[it]){
                        break;
                    }
                    it++;
                    is--;
                }
                if(it == k){
                    found = true;
                    break;
                }
            }
        }

        if(found)
            cout <<"YES" << endl;
        else
            cout << "NO" << endl;

    }
    return 0;
}