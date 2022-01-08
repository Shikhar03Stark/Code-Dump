#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

string solve(string& s, int a, int b, int left, int right){
    if(left >= right){
        int n = s.size();
        if(s[n/2] == '?'){
            if(a==1){
                s[n/2] = '0';
                a--;
            }
            else if(b == 1){
                s[n/2] = '1';
                b--;
            }
            else{
                return "-1";
            }
        }
       if(a != 0 || b != 0){
           return "-1";
       }
        return s;
    }
    if(s[left] == '?' && s[right] == '?'){
        s[left] = '0', s[right] = '0';
        if(solve(s, a-2, b, left+1, right-1) != "-1"){
            return s;
        }
        s[left] = '1', s[right] = '1';
        if(solve(s, a, b-2, left+1, right-1) != "-1"){
            return s;
        }
        s[left] = '?', s[right] = '?';
        return "-1";
    }

    if(s[left] == '?'){
        if(s[right] == '1'){
            b--;
        }
        else{
            a--;
        }
        s[left] = s[right];
        return solve(s, a, b, left+1, right-1);
    }
    if(s[right] == '?'){
        if(s[left] == '1'){
            b--;
        }
        else{
            a--;
        }
        s[right] = s[left];
        return solve(s, a, b, left+1, right-1);
    }

    return solve(s, a, b, left+1, right-1);

}

int main(){
    int t;
    cin>>t;
    while(t--){
        int a, b;
        cin >> a >> b;
        string s;
        cin >> s;
        int n = s.size();
        int ques = 0, ones = 0, zeros = 0;
        for(int i = 0; i<n; i++){
            if(s[i] == '?')
                ques++;
            if(s[i] == '1')
                ones++;
            if(s[i] == '0')
                zeros++;
        }

        a -= zeros;
        b -= ones;
        //b = max(0,b);
        if(a + b != ques || a < 0 || b < 0){
            cout << -1 << endl;
            continue;
        }
        bool possible = true;
        for(int i = 0; i<n/2 ;i++){
            if((s[i] != '?' && s[n-i-1] != '?') && s[i] != s[n-i-1]){
                cout << -1 << endl;
                possible = false;
                break;
            }
        }
        if(!possible){
            continue;
        }

        string ans = solve(s, a, b, 0, s.size()-1);

        cout << ans << endl;

        /*int left = 0, right = n-1;
        while(left<right){
            if(s[left] == '?' && s[right] == '?'){
                if(a>=b){
                    s[left] = '0';
                    s[right] = '0';
                    a -= 2;
                }
                else{
                    s[left] = '1';
                    s[right] = '1';
                    b -= 2;
                }
            }
            else if(s[left] == '?'){
                if(s[right] == '0'){
                    a--;
                }
                else{
                    b--;
                }
                s[left] = s[right];
            }
            else if(s[right] == '?'){
                if(s[left] == '0'){
                    a--;
                }
                else{
                    b--;
                }
                s[right] = s[left];
            }

            if(a < 0 || b < 0){
                possible = false;
                break;
            }
            ++left;
            --right;
        }

        if(n%2 == 1){
            if(s[n/2] == '?'){
                if(a == 1){
                    s[n/2] = '0';
                }
                else if(b == 1){
                    s[n/2] = '1';
                }
                else{
                    possible = false;
                }
            }
        }

        if(possible){
            cout << s << endl;
        }
        else{
            cout << -1 << endl;
        }*/
    }
    return 0;
}