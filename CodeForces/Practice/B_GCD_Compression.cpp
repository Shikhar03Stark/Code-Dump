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
        vector<int> arr(2*n);
        for(auto&e: arr){
            cin >> e;
        }
        vector<int> even, odd;
        int e = 0, o = 0;
        for(int i = 0; i<2*n; i++){
            if(arr[i]%2 == 0){
                even.push_back(i);
                e++;
            }
            else{
                //even[i]=0;
                odd.push_back(i);
                o++;
            }
        }

        if(o%2==0 && e%2==0){
            if(!even.empty()){
                even.pop_back();
                even.pop_back();
            }
            else{
                odd.pop_back();
                odd.pop_back();
            }
        }
        else{
            even.pop_back();
            odd.pop_back();
        }

        for(int i = 0; i<even.size(); i+=2){
            cout << even[i]+1 << " " << even[i+1]+1 << endl;
        }
        for(int i = 0; i<odd.size(); i+=2){
            cout << odd[i]+1 << " " << odd[i+1]+1 << endl;
        }
    }
    return 0;
}