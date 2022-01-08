#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

bool isStaright(char c){
    if(c == '1' or c == '2') return true;
    return false;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        vector<string> grid(2);
        for(int i = 0; i<2; i++){
            string s;
            cin >> s;
            grid[i] = s;
        }
        for(int i = 0; i<2; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == '1'){
                    grid[i][j] = '2';
                }
            }
        }

        int r = 0, c;
        bool pos = true;
        for(c = 0; c<n; c++){
            if(!isStaright(grid[r][c])){
                if(r==0){
                    //try down
                    if(!isStaright(grid[r+1][c])){
                        r = 1;
                    }
                    else{
                        pos = false;
                        break;
                    }
                }
                else{
                    //try up
                    if(!isStaright(grid[r-1][c])){
                        r = 0;
                    }
                    else{
                        pos = false;
                        break;
                    }
                }
            }
        }
        if(pos && c==n && r==1){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}