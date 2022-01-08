#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define F first
#define S second
#define dev(x) cerr << #x << x << endl
using namespace std;

struct Matrix{
    vector<vector<int>> mat;
    pair<int,int> start, end;
    int row, col;

    Matrix(){
        start = {0,0};
        end = {0,0};
        row = 0;
        col = 0;
    }

    Matrix(vector<vector<int>> &Mat){
        mat = Mat;
        start = {0,0};
        end = {Mat.size(), Mat[0].size()};
        row = end.first - start.first;
        col = end.second - start.second;
    }
};

void merge_row(vector<vector<int>>& mat, pair<int,int> start, pair<int,int> end, int col_cut){
    for(int r = start.F; r<=end.F; r++){
        vector<int> aux(end.S-start.S+1);
        int k = 0, i = start.S, j = col_cut+1;

        while(i<=col_cut && j<=end.S){
            if(mat[r][i] <= mat[r][j]){
                aux[k] = mat[r][i];
                i++;
            }
            else{
                aux[k] = mat[r][j];
                j++;
            }
            k++;
        }

        while(i<=col_cut){
            aux[k] = mat[r][i];
            i++;
            k++;
        }

        while(j<=end.S){
            aux[k] = mat[r][j];
            j++;
            k++;
        }

        for(int p = start.S; p<=end.S; p++){
            mat[r][p] = aux[p-start.S];
        }
    }
}

void merge_col(vector<vector<int>>& mat, pair<int,int> start, pair<int,int> end, int row_cut){
    for(int c = start.S; c <= end.S; c++){
        vector<int> aux(end.F - start.F + 1);
        int k = 0, i = start.F, j = row_cut+1;

        while(i<=row_cut && j<=end.F){
            if(mat[i][c] <= mat[j][c]){
                aux[k] = mat[i][c];
                i++;
            }
            else{
                aux[k] = mat[j][c];
                j++;
            }
            k++;
        }

        while(i<=row_cut){
            aux[k] = mat[i][c];
            i++;
            k++;
        }

        while(j<=end.F){
            aux[k] = mat[j][c];
            j++;
            k++;
        }

        for(int p = start.F; p<=end.F; p++){
            mat[p][c] = aux[p-start.F];
        }
    }
}

void Merge(vector<vector<int>>& mat, pair<int,int> start, pair<int,int> end, int row_cut, int col_cut){
    merge_row(mat, start, end, col_cut);
    merge_col(mat, start, end, row_cut);
}


/**
 * mat[start..end][start...end], end is inclusive
*/
void MergeSort2D(vector<vector<int>>& mat, pair<int,int> start, pair<int,int> end){
    int row_cut = (start.F + end.F)/2, col_cut = (start.S + end.S)/2;
    if(start.F > end.F || start.S > end.S){
        return;
    }
    if(start.F == end.F){
        if(start.S == end.S){
            return ;
        }
    }
    if(start.S == end.S){
        if(start.F == end.F){
            return ;
        }
    }

    MergeSort2D(mat, start, {row_cut, col_cut});
    MergeSort2D(mat, {start.F, col_cut+1}, {row_cut, end.S});
    MergeSort2D(mat, {row_cut+1, start.S}, {end.F, col_cut});
    MergeSort2D(mat, {row_cut+1, col_cut+1}, end);

    Merge(mat, start, end, row_cut, col_cut);
    
}

int main(){
    int m, n;
    cin >> m >> n;
    vector<vector<int>> vec(m, vector<int>(n));
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            cin >> vec[i][j];
        }
    }
    if(m == 0 || n == 0){
        return 0;
    }

    MergeSort2D(vec, {0,0}, {vec.size()-1, vec[0].size()-1});
    for(auto& row: vec){
        for(auto& e: row){
            cout << e << " ";
        }
    }
    cout << endl;
    /*for(auto& row : vec){
        for(auto& e: row){
            cout << e << " ";
        }
        cout << endl;
    }
    cout << "----" << endl;
    merge_row(vec, {0,0}, {2,3}, 1);
    for(auto& row : vec){
        for(auto& e: row){
            cout << e << " ";
        }
        cout << endl;
    }
    cout << "-----" << endl;
    merge_col(vec, {0,0}, {2,3}, 1);
    for(auto& row : vec){
        for(auto& e: row){
            cout << e << " ";
        }
        cout << endl;
    }
    cout << "-------" << endl;*/

    return 0;
}