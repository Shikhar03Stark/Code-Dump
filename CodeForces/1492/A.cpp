#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        unsigned ll p, a, b, c;
        cin >> p >> a >> b >> c;

        cout << min({(a - p%a)%a, (b-p%b)%b, (c - p%c)%c}) << endl;
    }
    return 0;
}