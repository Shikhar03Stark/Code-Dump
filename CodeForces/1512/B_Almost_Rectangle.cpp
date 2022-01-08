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
        vector<string> grid(n);
        for(auto& s : grid){
            cin >> s;
        }
        pair<int,int> first = {-1,-1}, second = {-1,-1};
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == '*'){
                    if(first.first == -1){
                        first.first = i;
                        first.second = j;
                    }
                    else{
                        second.first = i;
                        second.second = j;
                    }
                }
            }
        }

        pair<int, int> third, fourth;
        if(first.first == second.first){
            if(first.first == 0){
                third = {1, first.second};
                fourth = {1, second.second};
            }
            else if(first.first == n-1){
                third = {n-2, first.second};
                fourth = {n-2, second.second};
            }
            else{
                third = {first.first+1, first.second};
                fourth = {second.first+1, second.second};
            }
        }
        else if(first.second == second.second){
            if(first.second == 0){
                third = {first.first, 1};
                fourth = {second.first, 1};
            }
            else if(first.second == n-1){
                third = {first.first, n-2};
                fourth = {second.first, n-2};
            }
            else{
                third = {first.first, first.second+1};
                fourth = {second.first, second.second+1};
            }
        }
        else{
            third = {first.first, second.second};
            fourth = {second.first, first.second};
        }

        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(first == make_pair(i,j) || second == make_pair(i,j) || third == make_pair(i,j) || fourth == make_pair(i,j)){
                    cout << '*';
                }
                else{
                    cout << '.';
                }
            }
            cout << endl;
        }
    }
    return 0;
}