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
        int n;
        cin >> n;
        vector<int> timetable(n);
        for(int i = 0; i<n; i++){
            cin >> timetable[i];
        }
        vector<int> req(n);
        for(int i = 0; i<n; i++){
            cin >> req[i];
        }
        int prev = 0;
        int cnt = 0;
        for(int i = 0; i<n; i++){
            int left = timetable[i] - prev;
            req[i] = left - req[i];
            prev = timetable[i];
            cnt += (req[i]>=0)?1:0;
        }

        cout << cnt << endl;
    }
    return 0;
}