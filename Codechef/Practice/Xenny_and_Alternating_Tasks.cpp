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
        for(int i = 0; i<n; i++){
            cin >> a[i];
        }
        for(int i = 0; i<n; i++){
            cin >> b[i];
        }
        bool flag = true;
        int suma = 0, sumb = 0;
        for(int i = 0; i<n; i++){
            suma += (flag)?a[i]:b[i];
            sumb += (flag)?b[i]:a[i];

            flag  = !flag;
        }

        cout << min(suma, sumb) << endl;
    }
    return 0;
}