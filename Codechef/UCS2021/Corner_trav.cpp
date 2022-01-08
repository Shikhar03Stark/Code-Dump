#include <iostream>
#include <vector>
#include <set>
#include <bitset>
#include <queue>
#include <utility>
#include <climits>

using namespace std;

const int NODES = 3000;

class Cell {
    public:
    vector<bool> allowed;
    int val;
};

void printCells(vector<Cell>& path){
    for(int i = 0; i<path.size(); i++){
        cout << path[i].val << " ";
    }
    cout << endl;
}

Cell& getCell(vector<vector<Cell>>& grid, pair<int,int> coord){
    return grid[coord.first][coord.second];
}

vector<pair<int,int>> getAllowedCoords(vector<vector<Cell>>& grid, pair<int,int> coord){
    int y = coord.first, x = coord.second;
    int add[][2] = {
        {-1,0},
        {-1,1},
        {0,1},
        {1,1},
        {1,0},
        {1,-1},
        {0,-1},
        {-1,-1}
    };

    vector<pair<int,int>> ans;
    Cell c = getCell(grid, coord);
    for(int i = 0; i<8; i++){
        if(c.allowed[i] == true){
            ans.push_back({coord.first + add[i][0], coord.second + add[i][1]});
        }
    }
    return ans;
}

vector<Cell> bidir_bfs_path(vector<vector<Cell>>& grid, pair<int,int> source, pair<int,int> target){
    if(source == target){
        return vector<Cell>(1,grid[source.first][source.second]);
    }
    bool source_turn = true;
    queue<vector<pair<int,int>>> source_path, target_path;
    set<int> source_vis, target_vis;
    source_vis.insert(getCell(grid, source).val);
    target_vis.insert(getCell(grid, target).val);
    source_path.push({source});
    target_path.push({target});

    vector<Cell> ans;

    while(!source_path.empty() && !target_path.empty()){
        if(source_turn){
            int level = source_path.size();
            vector<pair<int,int>> latest_path = source_path.front();
            //source_path.pop();
            pair<int,int> latest_cell = latest_path[latest_path.size()-1];
            Cell cell = getCell(grid, latest_cell);

            //if cell.val is found in target_vis, shortest path found
            if(target_vis.count(cell.val) > 0){
                //find path from target queue, with last cell = cell.val;
                vector<pair<int,int>> t_path;
                int size = INT_MAX;
                while (!target_path.empty())
                {
                    vector<pair<int,int>> aux_path = target_path.front();
                    target_path.pop();
                    Cell c = getCell(grid, aux_path[aux_path.size()-1]);
                    if(c.val == cell.val){
                        if(aux_path.size() < size){
                            t_path = aux_path;
                            size = aux_path.size();
                        }

                    }
                }
                
                for(int i = 0; i<latest_path.size(); i++){
                    ans.push_back(getCell(grid, latest_path[i]));
                }
                //printCells(ans);
                for(int i = t_path.size()-2; i>=0; i--){
                    ans.push_back(getCell(grid, t_path[i]));
                }
                //cout << "FULL\n";
                //printCells(ans);

                break;
            }
            else{
                for(int i = 0; i<level; i++){
                    vector<pair<int,int>> latest_path = source_path.front();
                    source_path.pop();
                    pair<int,int> latest_cell = latest_path[latest_path.size()-1];
                    Cell cell = getCell(grid, latest_cell);
                    
                    vector<pair<int,int>> adj_cells = getAllowedCoords(grid, latest_cell);
                    for(int i = 0; i<adj_cells.size(); i++){
                        Cell c = getCell(grid, adj_cells[i]);
                        if(source_vis.count(c.val) == 0){
                            //create new copy of path and add to source_queue
                            source_vis.insert(c.val);
                            vector<pair<int,int>> new_path = latest_path;
                            new_path.push_back(adj_cells[i]);
                            source_path.push(new_path);
                        }
                    }
                }
            }
        }
        else{
            vector<pair<int,int>> latest_path = target_path.front();
            target_path.pop();
            pair<int,int> latest_cell = latest_path[latest_path.size()-1];
            Cell cell = getCell(grid, latest_cell);

            //if cell.val is found in source_vis, shortest path found
            if(source_vis.count(cell.val) > 0){
                //find path from source queue, with last cell = cell.val;
                vector<pair<int,int>> t_path;
                int size = INT_MAX;
                while (!source_path.empty())
                {
                    vector<pair<int,int>> aux_path = source_path.front();
                    source_path.pop();
                    Cell c = getCell(grid, aux_path[aux_path.size()-1]);
                    if(c.val == cell.val){
                        if(aux_path.size() < size){
                            t_path = aux_path;
                            size = aux_path.size();
                        }

                    }
                }
                
                for(int i = 0; i<t_path.size(); i++){
                    ans.push_back(getCell(grid, t_path[i]));
                }
                for(int i = latest_path.size()-2; i>=0; i--){
                    ans.push_back(getCell(grid, latest_path[i]));
                }

                break;
            }
            else{
                vector<pair<int,int>> adj_cells = getAllowedCoords(grid, latest_cell);
                for(int i = 0; i<adj_cells.size(); i++){
                    Cell c = getCell(grid, adj_cells[i]);
                    if(target_vis.count(c.val) == 0){
                        //create new copy of path and add to source_queue
                        target_vis.insert(cell.val);
                        vector<pair<int,int>> new_path = latest_path;
                        new_path.push_back(adj_cells[i]);
                        target_path.push(new_path);
                    }
                }
            }

        }
        source_turn = !source_turn;
    }

    return ans;
}


int main(){
    int m, n, source_val;
    cin >> m >> n >> source_val;
    vector<vector<Cell>> grid(m, vector<Cell>(n));
    pair<int,int> source;
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            cin >> grid[i][j].val;
            if(grid[i][j].val == source_val){
                source = {i, j};
            }
            for(int k = 0; k<8; k++){
                bool dir;
                cin >> dir;
                grid[i][j].allowed.push_back(dir);
            }
        }
    }

    vector<Cell> p1 = bidir_bfs_path(grid, source, {0,0});
    vector<Cell> p2 = bidir_bfs_path(grid, source, {0,n-1});
    vector<Cell> p3 = bidir_bfs_path(grid, source, {m-1,0});
    vector<Cell> p4 = bidir_bfs_path(grid, source, {m-1,n-1});

    printCells(p1);
    printCells(p2);
    printCells(p3);
    printCells(p4);

    return 0;
}