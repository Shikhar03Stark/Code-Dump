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
        vector<int> me, other;
        for(int i = 0 ;i <n; i++){
            int data;
            cin >> data;
            me.push_back(data);
        }
        for(int i = 0 ;i <n; i++){
            int data;
            cin >> data;
            other.push_back(data);
        }
        int add = 0;
        sort(begin(me), end(me), greater<int>());
        sort(begin(other), end(other), greater<int>());
        vector<int> pme(n+1, 0), pother(n+1, 0);
        for(int i = 0; i<n; i++){
            pme[i+1] = pme[i] + me[i];
            pother[i+1] = pother[i] + other[i];
        }

        int count = n -n/4;
        int sumMe = 0, sumOther = 0;
        if(pme[count] >= pother[count]){
            cout << 0 << endl;
            continue;
        }

        int rounds = n;
        int idx = count;
        while(idx<=n){
            
        }

    }
    return 0;
}