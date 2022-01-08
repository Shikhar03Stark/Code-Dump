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
        vector<set<int>> arr(n);
        for(int i = 0; i<n; i++){
            int k;
            cin >> k;
            for(int j = 0; j<k; j++){
                int data;
                cin >> data;
                arr[i].insert(data);
            }
        }

        set<int> taken;
        vector<int> left;
        for(int i = 0; i<n; i++){
            bool found = false;
            for(int ideal: arr[i]){
                if(taken.find(ideal) == taken.end()){
                    taken.insert(ideal);
                    found = true;
                    break;
                }
            }
            if(!found){
                left.push_back(i);
            }
        }


        if(taken.size() == n){
            cout << "OPTIMAL" << endl;
        }
        else{
            cout << "IMPROVE" << endl;
            vector<int> kingd;
            int i = 1;
            
            for(int i = 1; i<=n; i++){
                if(taken.find(i) == taken.end()){
                    kingd.push_back(i);
                }
            }

            cout << left[0]+1 << " " << kingd[0] << endl;
        }
    }
    return 0;
}