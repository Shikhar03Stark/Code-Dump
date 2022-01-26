// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

int n, m;

bool inside(int r, int c){
    if(r<0 || r>=n || c<0 || c>=m) return false;
    return true;
}

bool invert(vector<vector<int>> &A, vector<vector<int>> &B, int r, int c){
    //UL
    vector<int> badrow, badcol;
    for(int i = 0; i<n; i++){
        if(i!=r && A[i][c] != B[i][c]){
            badrow.push_back(i);
        }
    }
    for(int j = 0; j<m; j++){
        if(j!=c && A[r][j] != B[r][j]){
            badcol.push_back(j);
        }
    }

    cerr << "BADROW: ";
    for(auto& e: badrow){
        cerr << e << " ";
    }
    cerr << nl;
    cerr << "BADCOL: ";
    for(auto& e: badcol){
        cerr << e << " ";
    }
    cerr << nl;

    for(int i = 0; i<badrow.size(); i++){
        for(int j = 0; j<badcol.size(); j++){
            if(A[badrow[i]][badcol[j]] != B[badrow[i]][badcol[j]]){
                A[badrow[i]][c] = !A[badrow[i]][c];
                A[r][badcol[j]] = !A[r][badcol[j]];
                A[badrow[i]][badcol[j]] = !A[badrow[i]][badcol[j]];
                cerr << "Inverting " << badrow[i] << " " << badcol[j] << nl;
                return true;
            }
        }
    }
    
    return false;
}

void solve(){
    cin >> n >> m;
    vector<vector<int>> A(n, vector<int>(m)), B(n, vector<int>(m));
    for(auto& row: A){
        for(auto&e: row){
            cin >> e;
        }
    }
    for(auto& row: B){
        for(auto&e: row){
            cin >> e;
        }
    }

    bool pos = true;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(A[i][j] != B[i][j]){
                cerr << "FOR: " << i << " " << j << nl;
                if(invert(A, B, i, j)){
                    A[i][j] = !A[i][j];
                }
            }
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(A[i][j] != B[i][j]){
                cout << "No" << nl;
                return;
            }
        }
    }

    cout << "Yes" << nl;

    
    return;
}

int main(){
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}