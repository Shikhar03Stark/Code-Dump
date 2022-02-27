// Author: Harshit Vishwakarma (Shikhar03Stark)
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

ll dist(ll x1, ll y1, ll x2, ll y2, ll x0, ll y0){
    ll dx1 = x1-x0, dx2 = x2-x0, dy1 = y1-y0, dy2 = y2-y0;
    if (dx1*dx2 > 0 && dy1*dy2 > 0){
        return min(abs(dx1), abs(dx2)) + min(abs(dy1), abs(dy2));
    }
    else if(dx1*dx2 > 0){
        return min(abs(dx1), abs(dx2));
    }
    else if(dy1 * dy2 > 0){
        return min(abs(dy1), abs(dy2));
    }
    else{
        return 0;
    }
}

void solve2(){
    ll k;
    cin >> k;
    vector<vector<ll>> coord(k, vector<ll>(4));
    for(auto& e: coord){
        for(auto& c: e){
            cin >> c;
        }
    }
    ll ansx = -100, ansy = -100;
    ll ans = INT_MAX;
    for(ll x = -100; x<=100; x++){
        for(ll y = -100; y<=100; y++){
            ll d = 0;
            for(auto& c: coord){
                d += dist(c[0], c[1], c[2], c[3], x, y);
            }
            if(d<=ans){
                if(d==ans){
                    if(ansx > x){
                        ansx = x;
                    }
                    if(ansy > y){
                        ansy = y;
                    }
                }
                else{
                    ansx = x;
                    ansy = y;
                }
                ans = d;
            }
        }
    }
    cout << ansx << " " << ansy << nl;
    return;
}

ll distSeq(vector<pair<ll,ll>> &X, ll x0){
    ll d = 0;
    int k = X.size();
    for(int i = 0; i<k; i++){
        if(x0 < X[i].first){
            d += X[i].first - x0;
        }
        else if(x0 > X[i].first + X[i].second){
            d += x0 - X[i].first - X[i].second;
        }
    }

    return d;
}

void solve(){
    ll k;
    cin >> k;
    vector<vector<ll>> coord(k, vector<ll>(4));
    for(auto& e: coord){
        for(auto& c: e){
            cin >> c;
        }
    }
    vector<pair<ll,ll>> X(k), Y(k);
    for(int i = 0; i<k; i++){
        X[i] = {coord[i][0], coord[i][2]-coord[i][0]};
        Y[i] = {coord[i][1], coord[i][3]-coord[i][1]};
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());

    ll ansxl = -1e9, ansxr = 1e9;
    while(ansxl < ansxr){
        ll m1 = ansxl + (ansxr-ansxl)/3;
        ll m2 = ansxr - (ansxr-ansxl)/3;
        cerr << "(" << ansxl << " " << ansxr << ")\n";
        ll f1 = distSeq(X, m1);
        ll f2 = distSeq(X, m2);
        if(f1 < f2){
            cerr << "L is min\n";
            ansxl = m1;
        }
        else{
            cerr << "R is min\n";
            ansxr = m2;
        }
    }

    cerr << "X " << ansxl << " " << ansxr << nl;

}

int main(){
    FASTIO
    pre();
    int T=1;
    cin>>T;
    for(int z = 1; z<=T; z++){
        cout << "Case #" << z << ": ";
        solve();
    }
    return 0;
}