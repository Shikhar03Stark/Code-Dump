#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> bishop(n);
    for(auto& b: bishop){
        cin >> b.first >> b.second;
    }
    //sort(bishop.begin(), bishop.end());
    map<int,int> low_diag, up_diag;
    ll pairs = 0;
    for(int i = 0; i<n; i++){
        int r = bishop[i].first, c = bishop[i].second;
        low_diag[c-r]++;
        up_diag[c+r]++;
    }

    for(int i = -1000; i<=1000; i++){
        ll cnt = max(0,low_diag[i]);
        pairs += cnt*(cnt-1)/2;
    }

    for(int i = 0; i<=2000; i++){
        ll cnt = max(0, up_diag[i]);
        pairs += cnt*(cnt-1)/2;
    }

    cout << pairs << endl;
    return 0;
}