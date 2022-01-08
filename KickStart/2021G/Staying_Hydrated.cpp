#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

ll dx(vector<vector<ll>> &pts, ll x, ll y){
    ll dist = 0;
    for(auto& pt: pts){
        if( (x < pt[0] || x > pt[2]) && (y<pt[1] && y>pt[3]))
            dist += min(abs(x-pt[0]), abs(x-pt[2])) + min(abs(y-pt[1]), abs(y-pt[3]));
    }
    return dist;
}

ll dy(vector<vector<ll>> &pts, ll y){
    ll dist = 0;
    for(auto& pt: pts){
        dist += min(abs(y-pt[1]), abs(y-pt[3]));
    }
    return dist;
}

int main(){
    int t;
    cin>>t;
    for(int z = 1; z<=t; z++){
        cout << "Case #" << z << ": ";
        ll m;
        cin >> m;
        vector<vector<ll>> pts(m, vector<ll>(4,0));
        ll minx = INT_MAX, miny = INT_MAX, maxx = INT_MIN, maxy = INT_MIN;
        for(auto& pt: pts){
            cin >> pt[0] >> pt[1] >> pt[2] >> pt[3];
            minx = min(minx, pt[0]);
            maxx = max(maxx, pt[2]);

            miny = min(miny, pt[1]);
            maxy = max(maxy, pt[3]);
        }

        ll midx, midy;
        while(miny <= maxy){
            midy = miny + (maxy-miny)/2;
            ll d = dy(pts, midy), dl = dy(pts, midy-1), dr = dy(pts, midy+1);
            if(dl >= d && d <= dr){
                break;
            }
            if(dl <= d){
                maxy = midy-1;
            }
            else{
                miny = midy+1;
            }
        }
        while(minx <= maxx){
            midx = minx + (maxx-minx)/2;
            ll d = dx(pts, midx, midy), dl = dx(pts, midx-1, midy), dr = dx(pts, midx+1, midy);
            if(dl >= d && d <= dr){
                break;
            }
            if(dl <= d){
                maxx = midx-1;
            }
            else{
                minx = midx+1;
            }
        }


        cout << midx << " " << midy << endl;
    }
    return 0;
}