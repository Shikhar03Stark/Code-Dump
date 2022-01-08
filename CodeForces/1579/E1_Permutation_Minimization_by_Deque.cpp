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
        vector<int> arr(n);
        for(int i = 0; i<n; i++){
            cin >> arr[i];
        }
        deque<int> Q;
        for(auto& e: arr){
            if(!Q.empty()){
                if(e < Q.front()){
                    Q.push_front(e);
                }
                else{
                    Q.push_back(e);
                }
            }
            else{
                Q.push_back(e);
            }
        }

        while(!Q.empty()){
            cout << Q.front() << ' ';
            Q.pop_front();
        }
        cout << endl;
    }
    return 0;
}