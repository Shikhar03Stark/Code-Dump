#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

int r, c;
vector<vector<int>> grid(1);

//dir 0 U, 1 R, 2 D, 3 L

int dfs(int i, int j, int dir){
    if(i < 0 || j < 0 || i >=r || j >=c)
        return 0;
    if(grid[i][j] == 0){
        return 0;
    }

    if(dir == 0){
        return 1 + dfs(i-1, j, dir);
    }
    else if(dir == 1){
        return 1 + dfs(i,j+1, dir);
    }
    else if(dir == 2){
        return 1 + dfs(i+1, j, dir);
    }
    else if(dir == 3){
        return 1+ dfs(i, j-1, dir);
    }
}

ll maxReach(int i, int j){
    int max[] = {0,0,0,0};
    max[0] = std::max(0,dfs(i,j,0));
    max[1] = std::max(0,dfs(i,j,1));
    max[2] = std::max(0,dfs(i,j,2));
    max[3] = std::max(0,dfs(i,j,3));
    ll L = 0;
    for(int i = 0; i<4; i++){
        int a = max[i];
        int b = max[(i+1)%4];
        int mm = std::min(a,b);
        int ma = std::max(a,b);
        ll low = mm;
        while(low*2 > ma){
            low--;
        }
        L += std::max((ll)0,(low-1));
        ll mlow = ma/2;
        while(mlow*2 > mm){
            mlow--;
        }
        L += std::max((ll)0, (mlow-1));
    }

    return L;

}

int main(){
    int t;
    cin>>t;
    for(int z = 1; z<=t; z++){
        cout << "Case #" << z << ": ";
        cin >> r >> c;
        grid.resize(r);
        for(auto& row : grid){
            row.resize(c);
        }
        for(int i = 0 ; i<r; i++){
            for(int j = 0; j<c ; j++){
                cin >> grid[i][j];
            }
        }

        //vector<vector<int>> vertex(r, vector<int>(c,0));
        unsigned ll L = 0;
        for(int i = 0; i<r; i++){
            for(int j = 0; j<c;j++){
                if(grid[i][j] == 1)
                    L += maxReach(i,j);
            }
        }

        cout << L << endl;
    }
    return 0;
}