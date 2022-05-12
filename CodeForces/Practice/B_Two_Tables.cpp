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

struct Point{
    double x, y;
};

void solve(){
    double W,H,x1,x2,y1,y2,w,h,ans;
    cin>>W>>H;
    cin>>x1>>y1>>x2>>y2;
    cin>>w>>h;
    double h2=H-y2, h1=y1, w1=x1, w2=W-x2;
    if(h+abs(y2-y1)>H && w+abs(x2-x1)>W) cout<<"-1"<<endl;
    else if(h+abs(y2-y1)<=H && w+abs(x2-x1)>W){
        cout<<fixed<< setprecision(10)<< max(min(h-h1,h-h2),0.0)<<endl;
    }
    else if(h+abs(y2-y1)>H && w+abs(x2-x1)<=W){
        cout<<fixed<< setprecision(10)<<max(min(w-w1,w-w2),0.0)<<endl;
    }
    else{
        cout<<fixed<< setprecision(10)<< min(max(min(h-h1,h-h2),0.0),max(min(w-w1,w-w2),0.0))<<endl;
    }

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