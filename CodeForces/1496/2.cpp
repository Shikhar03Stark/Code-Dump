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
        unordered_map<unsigned ll,int> h;
        set<int> S;
        for(int i = 0; i<n; i++){
            int j;
            cin >> j;
            S.insert(j);
            h[j]++;
        }
        /*int zero = -1;
        while(k>0){
            int mex, max;
            {
                if(zero == -1){
                    for(int i = 0; i<=100000;i++){
                        if(freq[i] == 0){
                            zero = i;
                            break;
                        }
                    }
                }
                mex = zero;
            }
            {
                max = *(S.rbegin());
            }
            int avg = ceil(((float)mex + max)/2);
            if(freq[avg] != 0){
                break;
            }
            else{
                freq[avg] = 1;
                S.insert(avg);
                if(zero == avg)
                    for(int i = zero; i<=100000; i++){
                        if(freq[i] == 0){
                            zero = i;
                            break;
                        }
                    }
            }
            --k;
        }

        cout << S.size() << endl;*/

        if(k == 0){
            cout << S.size() << endl;
        }
        else{
            int mex;
            int max = *(S.rbegin());
            for(int i = 0; i<=max; i++){
                if(h.count(i) == 0){
                    mex = i;
                    break;
                }
            }
            int avg = ceil(((double)mex + max)/2);
            if(mex < max){
                if(h.count(avg) == 0){
                    cout << S.size()+1 << endl;
                }
                else{
                    cout << S.size() << endl;
                }
            }
            else{
                unsigned ll s = S.size();
                cout << (s + k) <<endl;
            }
        }
    }
    return 0;
}