#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

int solve(string& s, int idx, int ga, int gb, int la, int lb){
    int n = s.size();
    if(idx>=n){
        return 20;
    }
    if(ga>gb){
        int diff = ga-gb;
        if(diff > lb)
            return idx+1;
    }
    else{
        int diff = gb-ga;
        if(diff > la)
            return idx+1;
    }
    if(s[idx] == '?'){
        if(idx%2 == 0){
            return min(solve(s, idx+1, ga+1, gb, la-1, lb), solve(s, idx+1, ga, gb, la-1, lb));
        }
        else{
            return min(solve(s, idx+1, ga, gb+1, la, lb-1), solve(s, idx+1, ga, gb, la, lb-1));
        }
    }
    if(s[idx] == '1'){
        if(idx%2 == 0){
            return solve(s, idx+1, ga+1, gb, la-1, lb);
        }
        else{
            return solve(s, idx+1, ga, gb+1, la, lb-1);
        }
    }
    if(s[idx] == '0'){
        if(idx%2 == 0){
            return solve(s, idx+1, ga, gb, la-1, lb);
        }
        else{
            return solve(s, idx+1, ga, gb, la, lb-1);
        }
    }
    return 0;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin >> s;
        int ans = solve(s, 0, 0, 0, 5, 5);
        if(ans == 20)
            cout << 10 << endl;
        else
            cout << ans-1 << endl;
        /*
        int ans = 10;
        int ga = 0, gb = 0, a = 0, b = 0;
        int kicks = ;
        for(int i = 0; i<s.size(); i++){
            if(s[i] != '0'){
                if(i%2==0){
                    if(s[i] == '1')   {
                        gb++;
                    }
                    else{
                        b++;
                    }
                }
                else{
                    if(s[i] == '1'){
                        ga++;
                    }
                    else{
                        a++;
                    }
                }
            }
            kicks++;
            bool end = false;
            for(int j = 0; j<=a; j++){
                for(int k = 0; k<=b; k++){
                    if(abs(ga + j - gb -k) > 10-kicks){
                        end = true;
                    }
                }
            }
            if(end)
                break;
        }

        cout << kicks << endl;*/

    }
    return 0;
}