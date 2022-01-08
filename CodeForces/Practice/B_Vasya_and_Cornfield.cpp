#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

int l1(int n, int d, int x, int y){
    return y-x-d;
}
int l2(int n, int d, int x, int y){
    return y-x+d;
}
int l3(int n, int d, int x, int y){
    return y+x-d;
}
int l4(int n, int d, int x, int y){
    return y+x-2*n+d;
}

int main(){
    int n, d;
    cin >> n >> d;
    int m;
    cin >> m;
    //vector<pair<int, int>> pts(m);
    for(int i = 0; i<m; i++){
        int x, y;
        cin >> x >> y;
        int v1 = l1(n, d, x, y), v2 = l2(n,d,x,y), v3 = l3(n, d, x, y), v4 = l4(n, d, x, y);
        if(v1*v2 <= 0 && v3*v4 <= 0){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }

    return 0;
}