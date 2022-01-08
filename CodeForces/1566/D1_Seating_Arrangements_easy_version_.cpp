#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

bool comp1(pair<int,int> a, pair<int,int> b){
    if(a.first<b.first) return true;
    if(a.first == b.first) {
        return a.second > b.second;
    }
    return false;
}

void inc(vector<int> &fen, int i){
    for(;i<fen.size(); i+=(i&-i)){
        fen[i]++;
    }
}

int sum(vector<int> &fen, int i){
    int tot = 0;
    for(;i>0; i -= (i&-i)){
        tot += fen[i];
    }
    return tot;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<pair<int,int>> arr(n*m);
        for(int i = 0; i<n*m; i++){
            int data;
            cin >> data;
            arr[i] = {data, i};
        }
        sort(arr.begin(), arr.end(), comp1);
        unordered_map<int,int> h;
        for(int i = 0; i<m*n; i++){
            h[arr[i].second] = i;
        }

        vector<int> fen(n*m+1, 0);
        int tot = 0;
        for(int i = 0; i<n*m; i++){
            int pre = sum(fen, h[i]+1);
            tot += pre;
            inc(fen, h[i]+1);
        }
        cout << tot << endl;


    }
    return 0;
}