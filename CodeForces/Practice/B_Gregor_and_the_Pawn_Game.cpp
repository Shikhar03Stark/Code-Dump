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
        cin >> n;
        vector<string> chess(2);
        for(int i = 0; i<2; i++){
            string s;
            cin >> s;
            chess[i] += s;
        }
        int cnt = 0;
        for(int i = 0; i<n; i++){
            if(chess[1][i] == '1' && chess[0][i] == '0'){
                chess[0][i] = '2';
                chess[1][i] = '0';
                cnt++;
            }
            else if(chess[1][i] == '1' && (chess[0][i] == '1' || chess[0][i] == '2')){
                if(i > 0 && chess[0][i-1] == '1'){
                    chess[0][i-1] = '2';
                    chess[1][i] = '0';
                    cnt++;
                }
                else if(i < n-1 && chess[0][i+1] == '1'){
                    chess[0][i+1] = '2';
                    chess[1][i] = '0';
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}