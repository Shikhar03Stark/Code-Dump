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
        string s;
        int n;
        cin >> n;
        cin >> s;
        int l = -1, r = -1;
        bool found = false;
        for(int i = 0; i<n & !found; i++){
            int cnta = 0, cntb = 0;
            for(int j = i; j<n; j++){
                if(s[j] == 'a') cnta++;
                if(s[j] == 'b') cntb++;
                if(cnta == cntb){
                    l = i+1;
                    r = j+1;
                    found = true;
                    break;
                }
            }
        }

        cout << l << " " << r << endl;

    }
    return 0;
}