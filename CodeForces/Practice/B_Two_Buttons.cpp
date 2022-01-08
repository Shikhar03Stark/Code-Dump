#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

int ans[10001];

int solve(int t, int s){
    if(t<=s){
        return ans[t] = s-t;
    }
    else{
        if(t%2 == 1){
            return 1+solve((t+1)/2, s);
        }
        else{
            return 1+solve(t/2, 2);
        }
    }
}

int main(){
    int s, t;
    cin >> s >> t;
    vector<bool> vis(1e4+1, false);
    int lvl = 0;
    queue<int> Q;
    Q.push(s);
    while(!Q.empty()){
        int size = Q.size();
        bool found = false;
        for(int i = 0; i<size; i++){
            int num = Q.front(); Q.pop();
            vis[num] = true;
            if(num == t){
                found = true;
                break;
            }
            if(num>t){
                if(num-1>0 && vis[num-1] == false){
                    Q.push(num-1);
                }
            }
            else{
                if(num-1>0 && vis[num-1] == false){
                    Q.push(num-1);
                }
                if(2*num <= 1e4 && vis[2*num]== false){
                    Q.push(2*num);
                }
            }
        }
        if(found) break;
        lvl++;
    }
    cout << lvl << endl;
    return 0;
}