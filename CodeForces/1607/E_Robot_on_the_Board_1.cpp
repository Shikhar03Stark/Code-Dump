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
        int m, n;
        cin >> m >> n;
        string ins;
        cin >> ins;
        int minx = 0, miny = 0, maxx = 0, maxy = 0, dx = 0, dy = 0, ansx = 1, ansy=1;
        for(auto&c:ins){
            if(c == 'L') dx--;
            if(c == 'R') dx++;
            if(c == 'U') dy--;
            if(c == 'D') dy++;
            minx = min(minx, dx), maxx = max(maxx, dx);
            miny = min(miny, dy), maxy = max(maxy, dy);
            int x = n - maxx;
            int y = m - maxy;
            if(x>=1 && x<=n && x+minx>=1 && y>=1 && y<=m && y+miny>=1){
                ansx = x;
                ansy = y;
            }
            else break;
        }
        cout << ansy << ' ' << ansx << endl;
    }
    return 0;
}