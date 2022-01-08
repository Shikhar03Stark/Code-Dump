#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

int main(){
    int n;
    cin >> n;
    unordered_map<string,int> h;
    for(int i = 0; i<n; i++){
        string s;
        cin >> s;
        if(h[s] == 0){
            cout << "OK" << endl;
            h[s]++;
        }
        else{
            string ns = s+to_string(h[s]);
            h[ns]++;
            h[s]++;
            cout << ns << endl;

        }
    }

    return 0;
}