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
        FASTIO
        cin.clear();
        fflush(stdin);
        int n;
        const int limit = 3* 1e5;
        bitset<limit> a, b;
        cin >> n;
        cin.clear();
        fflush(stdin);
        cin >> a;
        cin.clear();
        fflush(stdin);
        cin >> b;
        vector<int> flip;
        //cerr << b[limit-n+1] << endl;
        int sum = 0;
        for(int i = n-1; i>=0; i--){
            if(a[i] == 0){
                sum--;
            }
            if(a[i] == 1)
                sum++;
            if(sum == 0){
                flip.push_back(n-i-1);
            }
        }
        bool rev = false;
        bool possible = true;
        for(int i = 0; i<n; i++){
            bool aa = rev?~a[i]:a[i];
            //cerr << aa;
            if(aa != b[i] && binary_search(flip.begin(), flip.end(), i)){
                possible = false;
                break;
            }
            if(aa != b[i]){
                rev = !rev;
            }
        }
        for(int i = 0; i<n; i++){
            cerr << a[i] << b[i] << " ";
        }
        cerr << endl;
        if(!possible){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }
    }
    return 0;
}