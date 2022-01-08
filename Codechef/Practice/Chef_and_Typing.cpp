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
        vector<string> arr(n);
        for(int i = 0; i<n; i++){
            cin >> arr[i];
        }
        int tot = 0;
        map<string, int> h;
        for(auto& s: arr){
            if(h.count(s) > 0){
                tot += h[s]/2;
                //cout << "T " << h[s]/2 << endl;
                continue;
            }
            bool isleft = (s[0] == 'd' || s[0] == 'f')?true:false;
            int time = 2;
            for(int i = 1; i<s.size(); i++){
                if(s[i] == 'd' || s[i] == 'f'){
                    if(isleft){
                        time += 4;
                    }
                    else{
                        time += 2;
                    }
                    isleft = true;
                }
                else{
                    if(isleft){
                        time += 2;
                    }
                    else{
                        time += 4;
                    }
                    isleft = false;
                }
            }
            //cout << "T " << time << endl;
            h[s] = time;
            tot += time;
        }

        cout << tot << endl;
    }
    return 0;
}