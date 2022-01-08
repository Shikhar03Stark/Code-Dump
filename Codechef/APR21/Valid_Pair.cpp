#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    if(a == b || b == c || c == a)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;

}