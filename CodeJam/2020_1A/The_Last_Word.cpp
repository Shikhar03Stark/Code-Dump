#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int

using namespace std;

int main(){
    int t;
    cin>>t;
    for(int z = 1; z<=t; z++){
        cout << "Case #" << z << ": ";
        string s;
        cin >> s;
        char max;
        string ans = "";
        for(int i = 0; i<s.size(); i++){
            if(ans.empty()){
                max = s[i];
                ans.push_back(s[i]);
                continue;
            }
            if(s[i] >= max){
                max = s[i];
                ans.insert(ans.begin(), s[i]);
            }
            else{
                ans.push_back(s[i]);
            }
        }

        cout << ans << endl;

    }
    return 0;
}