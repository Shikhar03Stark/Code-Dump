#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin >> n >> k;
        ll sum = 0;
        vector<int> seq(n+1);
        for(int i = 1; i<=n;i++){
            if(i == 1){
                seq[i] = i;
            }
            if(i % 2 != 0 && i != 1)
                seq[i] = -i;
            else
            {
                seq[i] = i;
            }
            
        }
        int i = 1;
        for(;i<=n && k>0;i++){
            sum += seq[i];
            if(sum > 0){
                --k;
            }
        }
        bool travBack = false;
        if(k>0){
            //start from back
            travBack = true;
            for(int i = n; i>0 && k>0; i--){
                if(seq[i]<0){
                    seq[i] = i;
                    --k;
                }
            }
        }

        if(!travBack){
            for(;i<=n;i++){
                seq[i] = -i;
            }
        }

        for(int i = 1; i<=n;i++){
            cout << seq[i] << " ";
        }
        cout << endl;
        
    }
    return 0;
}