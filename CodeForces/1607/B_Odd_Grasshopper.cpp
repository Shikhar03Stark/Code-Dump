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
        ll n, x, div;
        cin >> x >> n;
        if(n == 0){
            cout << x << endl;
            continue;
        }
        n--;
        ll start = (n/4)*4+1;
        if(x%2==0){
            if(n%4==0){
                div = -start;
            }
            if(n%4==1){
                div = 1;
            }
            if(n%4==2){
                div = start+3;
            }
            if(n%4==3){
                div = 0;
            }
        }
        else{
            if(n%4==0){
                div = start;
            }
            if(n%4==1){
                div = -1;
            }
            if(n%4==2){
                div = -start-3;
            }
            if(n%4==3){
                div = 0;
            }
        }
        cout << x+div << endl;
    }
    return 0;
}