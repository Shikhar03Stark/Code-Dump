#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

enum directions {
    UP = 1,
    RIGHT = 2,
    DOWN = 3,
    LEFT = 4
};

void bfs(vector<pair<int,int>>& source, vector<pair<int,int>>& dest, int n, int m, int limit){
    int k = source.size();
    queue<pair<int,int>> Q;
    queue<string> path;
    path.push("");
    Q.push({0,0});
    int tries = 0;
    set<pair<int,int>> done;
    bool found = false;
    while(!Q.empty() && tries<limit){
        int size = Q.size();
        auto dir = Q.front();
        auto p = path.front();
        for(int i = 0; i<k; i++){
            if(min(n, max(0,source[i].first + dir.first)) == dest[i].first && min(m, max(0,source[i].second + dir.second)) == dest[i].second){
                done.insert(source[i]);
            }
        }
        if(done.size() == k){
            found = true;
            break;
        }
        Q.pop();
        path.pop();
        int d[] = {-1,0,1,0,-1};
        for(int i = 0; i<size; i++){
            for(int i = 1; i<5; i++){
                Q.push({dir.first+d[i-1], dir.second + d[i]});
                if(i == LEFT){
                    p.push_back('L');
                }
                if(i == RIGHT){
                    p.push_back('R');
                }
                if(i == UP){
                    p.push_back('U');
                }
                if(i == DOWN){
                    p.push_back('D');
                }
                path.push(p);
            }
        }

        ++tries;
    }

    if(!found){
        cout << -1 << endl;
    }
    else{
        cout << path.front().size() << endl;
        cout << path.front() << endl;
    }

}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m, k;
        cin >> n >> m >>k;
        vector<pair<int,int>> source;
        unordered_map<int,int> h;
        for(int i = 0; i<k; i++){
            int y, x;
            cin >> x >> y;
            source.push_back({y-1,x-1});
        }
        vector<pair<int, int>> dest;
        for(int i = 0; i<k; i++){
            int y,x;
            cin >> x >> y;
            dest.push_back({y-1,x-1});
        }

        bfs(source, dest, n, m, 2*n*m);
    }
    return 0;
}