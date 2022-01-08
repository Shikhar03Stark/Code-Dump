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
        ll W, H, x1, y1, x2, y2, w, h;
        cin >> W >> H;
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> w >> h;
        double ans = INT_MAX;
        ll dx=0, dy=0;
        if(x1>w)
            dx = x1-w;
        else
            dx = 0;
        if(H-h<y2)
            dy = y2-H+h;
        else
            dy = 0;
        if(dx == 0 || dy==0)
            ans = 0;
        if(dx!=0 && dy!=0 && x2+dx<=W && y1-dy>=0)
            ans = min(ans, sqrt(dx*dx+dy*dy));
        if(x1<w)
            dx = w-x1;
        else
            dx=0;
        if(y1<h)
            dy=h-y1;
        else
            dy=0;
        if(dx == 0 || dy==0)
            ans = 0;
        if(dx!=0 && dy != 0 && x2+dx <= W && y2+dy<=H)
            ans = min(ans, sqrt(dx*dx+dy*dy));
        if(x2>H-h)
            dx=x2-H+h;
        else
            dx=0;
        if(y1<h)
            dy = h-y1;
        else
            dy=0;
        if(dx == 0 || dy==0)
            ans = 0;
        if(dx!=0 && dy != 0 && x1-dx >=0 && y2+dy<=H)
            ans = min(ans, sqrt(dx*dx+dy*dy));
        if(x2>W-w)
            dx=x2-W+w;
        else
            dx=0;
        if(y2>H-h)
            dy=y2-H+h;
        else
            dy=0;
        if(dx == 0 || dy==0)
            ans = 0;
        if(dx!=0 && dy != 0 && x1-dx >=0 && y1-dy>=0)
            ans = min(ans, sqrt(dx*dx+dy*dy));
        
        if(ans == INT_MAX){
            cout << -1 << endl;
        }
        else{
            cout << setprecision(11) << ans << endl;
        }
    }
    return 0;
}