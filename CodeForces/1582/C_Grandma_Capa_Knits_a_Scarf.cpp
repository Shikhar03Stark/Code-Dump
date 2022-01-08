#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

int solve(string s, char del){
    int n = s.size();
    int i = 0, j = n-1;
    int cnt = 0;
    while(i<j){
        if(s[i] != s[j]){
            if(s[i]==del){
                i++;
                cnt++;
            }
            else if(s[j] == del){
                j--;
                cnt++;
            }
            else{
                return -1;
            }
        }
        else{
            i++;
            j--;
        }
    }
    return cnt;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        //FASTIO
        int n;
        cin >> n;
        string s;
        cin >> s;
        set<char> uniq;
        for(int i = 0; i<n; i++){
            uniq.insert(s[i]);
        }

        int min_change = INT_MAX;
        for(auto c:uniq){
            int ans = solve(s, c);
            if(ans != -1){
                min_change = min(min_change, ans);
            }
        }

        cout << (min_change==INT_MAX?-1:min_change) << endl;

    }
    return 0;
}