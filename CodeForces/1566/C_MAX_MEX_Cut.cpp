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
        vector<string> arr(2);
        for(int i = 0; i<2; i++){
            string s;
            cin >> s;
            arr[i] = s;
        }
        map<int,int> h;
        int tot = 0;
        for(int l = 0; l<n; l++){
            if(arr[0][l] == '1' && arr[1][l] == '1'){
                if(l>0 && arr[0][l-1] == '0' && arr[1][l-1] == '0' && h[l-1]==0){
                    h[l-1] = 1;
                    tot += 2;
                }
                else if(l<n && arr[0][l+1] == '0' && arr[1][l+1] == '0' && h[l+1] == 0){
                    h[l+1] = 1;
                    tot += 2;
                }
                h[l] = 1;
            }
        }
        for(int i = 0; i<n; i++){
            if(h[i] == 0){
                if(arr[0][i] == '0' && arr[1][i] == '0'){
                    tot +=1;
                }
                else{
                    tot += 2;
                }
            }
        }
        cout << tot << endl;
    }
    return 0;
}