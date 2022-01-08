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
        int n;
        string s;
        cin >> n;
        cin >> s;
        vector<vector<char>> ans(n, vector<char>(n, '='));
        vector<int> won(n, 0);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(i == j){
                    ans[i][j] = 'X';
                }
                else if(i < j){
                    if(s[i] == '1' && s[j] == '1'){
                        ans[i][j] = '=';
                    }
                    else if(s[i] == '1' && s[j] == '2'){
                        ans[i][j] = '+';
                        won[i]++;
                    }
                    else if(s[i] == '2' && s[j] == '1'){
                        ans[i][j] = '-';
                        won[j]++;
                    }
                    else{
                        if(won[i] == 0){
                            ans[i][j] = '+';
                            won[i]++;
                        }
                        else{
                            ans[i][j] = '-';
                            won[j]++;
                        }
                    }
                }
                else{
                    if(ans[j][i] == '+') ans[i][j] = '-';
                    if(ans[j][i] == '-') ans[i][j] = '+';
                    if(ans[j][i] == '=') ans[i][j] = '=';
                }
            }
        }

        bool satis = true;
        for(int i = 0; i<n; i++){
            if(s[i] == '2'){
                if(won[i] == 0){
                    satis = false;
                    break;
                }
            }
        }

        for(auto& row: ans){
            for(auto& e: row){
                cerr << e;
            }
            cerr << endl;
        }
        cerr << endl;
        if(satis){
            cout << "YES" << endl;
            for(auto& row: ans){
                for(auto& e: row){
                    cout << e;
                }
                cout << endl;
            }
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}