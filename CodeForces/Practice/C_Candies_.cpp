#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

int get(vector<int> &fen, int i){
    int ans = 0;
    for(;i>0; i -= (i&-i)){
        ans += fen[i];
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n+1, 0);
    for(int i = 1; i<=n; i++){
        cin >> arr[i];
    }
    vector<int> fen(n+1, 0);
    //build
    for(int i = 1; i<=n; i++){
        int start = i-(i&-i)+1;
        int candies = 0;
        for(;start<=i; start++){
            candies += arr[start];
        }
        //candies /= 10;
        fen[i] = candies;
    }
    /*for(auto& e: fen){
        cerr << e << " ";
    }
    cerr << endl;*/
    int q;
    cin >> q;
    for(int t = 0; t<q; t++){
        int l, r;
        cin >> l >> r;
        cout << (get(fen, r) - get(fen, l-1))/10 << endl;

    }
    return 0;
}