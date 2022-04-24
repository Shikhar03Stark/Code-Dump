// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

void pre(){
    
    return;
}

struct Node{
    char dir;
    Node* next;
    Node(char data):dir(data),next(nullptr){}
};

Node* dfs(vector<vector<int>> &grid, int r, int c, Node* parent, int &left){
    int m = grid.size(), n = grid[0].size();
    if(r < 0 || r >= m || c < 0 || c >= n) return nullptr;
    if(grid[r][c] != 0) return nullptr;
    if(left == 0) return parent;
    grid[r][c] = 1;
    left--;
    Node* d;
    Node* s = new Node('S');
    s->next = parent;
    d = dfs(grid, r+1, c, s, left);
    if(d) return d;

    Node* e = new Node('E');
    e->next = parent;
    d = dfs(grid, r, c+1, e, left);
    if(d) return d;

    Node* nn = new Node('N');
    nn->next = parent;
    d = dfs(grid, r-1, c, nn, left);
    if(d) return d;

    Node* w = new Node('W');
    w->next = parent;
    d = dfs(grid, r, c-1, w, left);
    if(d) return d;

    grid[r][c] = 0;
    left++;

    return nullptr;

}

void solve(){
    ll m, n;
    cin >> m >> n;
    vector<vector<int>> grid(2*m, vector<int>(2*n, 0));
    int chash = 0;
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            char c;
            cin >> c;
            if(c == '#'){
                chash++;
                for(int k = 2*i; k<2*i+2; k++){
                    for(int l = 2*j; l<2*j+2; l++){
                        grid[k][l] = -1;
                    }
                }
            }
        }
    }

    int tofill = 4*(m*n - chash);
    int rest = tofill;

    Node* ans = dfs(grid, 0, 0, new Node('0'), rest);
    if(ans){
        cout << "POS" << nl;
    }
    else{
        cout << "IMP" <<nl;
    }
    return;
}

int main(){
    FASTIO
    pre();
    int T=1;
    cin>>T;
    for(int z = 1; z<=T; z++){
        cout << "Case #" << z << ": ";
        solve();
    }
    return 0;
}