#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

bool prime[201];

bool iscomp(int n){
    if(n%2 == 0) return true;
    for(int i = 3; i*i<=n; i++){
        if(n%i == 0) return true;
    }
    return false;
}

int main(){
    prime[0] = prime[1] = 0;
    for(int i = 0; i<=200; i++){
        prime[i] = true;
    }
    for(int i = 2; i<=200; i++){
        if(prime[i]){
            for(int j = i*i; j<=200; j *= i){
                prime[j] = false;
            }
        }
    }
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(auto& e: arr){
            cin >> e;
        }
        int sum = 0;
        set<int> S;
        for(int i = 0; i<n; i++){
            sum += arr[i];
        }
        while(!iscomp(sum)){
            for(int i = 0; i<n; i++){
                if(iscomp(sum-arr[i])){
                    if(S.find(i) == S.end()){
                        S.insert(i);
                        sum -= arr[i];
                        break;
                    }
                }
            }
            if(!iscomp(sum)){
                int idx = n/2;
                while(idx >= 0 && S.find(idx) != S.end()){
                    idx--;
                }
                sum -= arr[idx];
                S.insert(idx);
            }
        }

        cout << n-S.size() << endl;
        for(int i = 0; i<n; i++){
            if(S.find(i) == S.end()){
                cout << i+1 << " ";
            }
        }
        cout << endl;
    }
    return 0;
}