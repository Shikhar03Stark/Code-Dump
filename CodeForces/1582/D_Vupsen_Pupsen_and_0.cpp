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
        vector<int> a(n);
        for(auto&e:a){
            cin >>e;
        }
        ll mini = 0;
        for(int i = 0; i<n; i++){
            if(abs(a[i]) < a[mini]){
                mini = i;
            }
        }
        ll low = abs(a[mini]);
        vector<int> b(n);
        bool pos = true;
        ll sum = 0;
        for(int i = 0; i<n; i++){
            if (i==mini) continue;
            if(sum>=0){
                if(a[i]>0){
                    if(sum-low*a[i] == 0){
                        b[i] = low;
                    }
                    else{
                        b[i] = -low;
                    }
                }
                else{
                    if(sum+low*a[i] == 0){
                        b[i] = -low;
                    }
                    else{
                        b[i] = low;
                    }
                }
            }
            else{
                if(a[i] > 0){
                    if(sum+low*a[i] == 0){
                        b[i] = -low;
                    }
                    else{
                        b[i] = low;
                    }
                }
                else{
                    if(sum-low*a[i] == 0){
                        b[i] = low;
                    }
                    else{
                        b[i] = -low;
                    }
                }
            }

            sum += a[i]*b[i];
        }
        b[mini] = -sum/a[mini];
        for(int i = 0; i<n; i++){
            cout << b[i] << " ";
        }
        cout << endl;

    }
    return 0;
}