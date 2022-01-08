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
        int upvotes = 0;
        for(int i = 0; i<n; i++){
            int data;
            cin >> data;
            if(data == 1 || data == 3){
                upvotes++;
            }
        }

        cout << upvotes << endl;
    }
    return 0;
}