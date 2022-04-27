// Author: Harshit Vishwakarma (Shikhar03Stark)
/*
1
1
2
1 2
2
1 3
2
2 3
3
1 2 3
2
1 4
2
2 4
3
1 2 4
2
3 4
3
1 3 4
3
2 3 4
4
1 2 3 4
2
1 5
2
2 5
3
1 2 5
2
3 5
3
1 3 5
3
2 3 5
4
1 2 3 5
2
4 5
3
1 4 5
3
2 4 5
4
1 2 4 5
3
3 4 5
4
1 3 4 5
4
2 3 4 5
5
1 2 3 4 5
2
1 6
2
2 6
3
1 2 6
2
3 6
3
1 3 6
3
2 3 6
4
1 2 3 6
2
4 6
3
1 4 6
3
2 4 6
4
1 2 4 6
3
3 4 6
4
1 3 4 6
4
2 3 4 6
5
1 2 3 4 6
2
5 6
3
1 5 6
3
2 5 6
4
1 2 5 6
3
3 5 6
4
1 3 5 6
4
2 3 5 6
5
1 2 3 5 6
*/

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

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto& e: arr){
        cin >> e;
    }
    if(n == 1) {
        cout << "YES" << nl;
        return ;
    }
    vector<pair<int,int>> cg;
    int i = 0; 
    while(i<n){
        int j = i;
        while(j+1<n && arr[j+1]-arr[j] == 1){
            j++;
        }
        cg.push_back({i, j});
        i = j+1;
    }
    if(cg.size() == 1){
        cout << "YES" << nl;
        return;
    }
    if(cg.size() > 3) {
        cout << "NO" << nl;
        return;
    }
    int curr = -1;
    for(int i = 1; i<cg.size(); i++){
        int last = arr[cg[i-1].second], first = arr[cg[i].first];
        int diff = first - last;
        if(diff == 2){
            if(curr == -1){
                curr++;
                continue;
            }
            if(curr == 0){
                curr++;
                continue;
            }
            if(curr >= 1){
                cout << "NO" << nl;
                return;
            }
        }
        else if(diff == 3){
            if(curr == -1){
                curr += 2;
                continue;
            }
            else if(curr >= 0){
                cout << "NO" << nl;
                return;
            }
        }
        else{
            cout << "NO" << nl;
            return;
        }
    }
    cout << "YES" << nl;
    return;
}

int main(){
    FASTIO
    pre();
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}