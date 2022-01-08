// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

int solve(){
    int x1, p1, x2, p2;
    cin >> x1 >> p1;
    cin >> x2 >> p2;
    //p1 = p1-p2;
    //p2 = 0;
    double d1 = x1, d2 = x2;
    while(d1 >= 10){
        d1 /= 10;
        p1++;
    }
    while(d2 >= 10){
        d2 /= 10;
        p2++;
    }
    if(p1>p2){
        cout << ">" << endl;
    }
    else if(p1<p2){
        cout << "<" << endl;
    }
    else{
        if(d1 < d2){
            cout << "<" << endl;
        }
        else if(d1 > d2){
            cout << '>' << endl;
        }
        else{
            cout << '=' << endl;
        }
    }

    return 0;
}

int main(){
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}