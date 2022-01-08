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
        vector<int> a(n), b(n);
        for(auto& e:a){
            cin >> e;
        }
        for(auto&e:b){
            cin >> e;
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        bool pos = true;
        for(int i = 0; i<n; i++){
            if(b[i]-a[i]<=1 && b[i]-a[i]>=0){}
            else{
                pos = false;
                break;
            }
        }

        cout << (pos?"YES":"NO") << endl;
    }
    return 0;
}