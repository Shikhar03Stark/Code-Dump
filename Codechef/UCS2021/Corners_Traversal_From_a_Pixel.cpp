#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

struct Pixel{
    vector<int> dir;
    int val;
};

vector<Pixel> bfs_path(vector<vector<Pixel>>& grid, pair<int,int> start, pair<int,int> end){
    deque<vector<pair<int,int>>> Q;
    set<pair<int,int>> vis;
    Q.push_back({start});
    int dir[][2] = {
        {-1,0},
        {-1,1},
        {0,1},
        {1,1},
        {1,0},
        {1,-1},
        {0,-1},
        {-1,-1}
    };
    int m = grid.size(), n = grid[0].size();
    while(!Q.empty()){
        if(Q.front()[Q.front().size()-1] == end){
            vector<Pixel> ans;
            vector<pair<int,int>> path = Q.front(); Q.pop_front();
            for(int i = 0; i<path.size(); i++){
                ans.push_back(grid[path[i].first][path[i].second]);
            }

            return ans;
        }
        vector<pair<int,int>> path = Q.front(); Q.pop_front();
        for(int j = 0; j<path.size(); j++){
            cerr << '(' << grid[path[j].first][path[j].second].val << ')' << ' ';
        }
        cerr << endl;
        pair<int,int> latest = path[path.size()-1];
        vis.insert(latest);
        Pixel p = grid[latest.first][latest.second];
        for(int k = 0; k<8; k++){
            int y = latest.first + dir[k][0], x = latest.second + dir[k][1];
            if(y < 0 || x < 0 || y >= m || x >= n || vis.count({y,x}) > 0){
                continue;
            }
            /*bool nodeInPath = false;
            for(int e = 0; e<path.size(); e++){
                if(path[e] == make_pair(y,x)){
                    nodeInPath = true;
                }
            }
            if(nodeInPath){
                continue;
            }*/
            if(p.dir[k]){
                vector<pair<int,int>> newPath = path;
                newPath.push_back({y,x});
                Q.push_back(newPath);
            }
        }

    }

    return {};

}

int main(){
    int m, n, s;
    cin >> m >> n >> s;
    pair<int,int> source;
    vector<vector<Pixel>> grid(m, vector<Pixel>(n));
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            cin >> grid[i][j].val;
            if(grid[i][j].val == s){
                source = {i,j};
            }
            grid[i][j].dir.resize(8);
            for(int k = 0; k<8; k++){
                cin >> grid[i][j].dir[k];
            }
        }
    }

    vector<Pixel> c1 = bfs_path(grid, source, {0,0});
    vector<Pixel> c2 = bfs_path(grid, source, {0,n-1});
    vector<Pixel> c3 = bfs_path(grid, source, {m-1,0});
    vector<Pixel> c4 = bfs_path(grid, source, {m-1,n-1});
    for(auto& e: c1){
        cout << e.val << " ";
    }
    cout << endl;

    for(auto& e: c2){
        cout << e.val << " ";
    }
    cout << endl;

    for(auto& e: c3){
        cout << e.val << " ";
    }
    cout << endl;

    for(auto& e: c4){
        cout << e.val << " ";
    }
    cout << endl;
    

    return 0;
}