#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

vector<bool> prime(201, true);
vector<int> p;
void genPrimes(){
    for(int i = 2; i*i<=200; i++){
        if(prime[i] == true){

            for(int j = i*i; j<=200; j+=i){
                prime[j] = false;
            }
        }
    }

    for(int i = 2; i<=200; i++){
        if(prime[i] == true) p.push_back(i);
    }

}

int main(){
    int t;
    cin>>t;
    genPrimes();
    while(t--){
        int n;
        cin >> n;
        unordered_map<int, bool> h;
        vector<int> semi;
        for(int i = 0; i<p.size(); i++){
            for(int j = i+1; j<p.size(); j++){
                if(p[i]*p[j] < n && h.count(p[i]*p[j]) == 0){
                    h[p[i]*p[j]] = true;
                    semi.push_back(p[i]*p[j]);
                }
            }
        }
        bool pos = false;
        for(int i = 0; i<semi.size(); i++){
            int res = n - semi[i];
            if(h.count(res) > 0){
                pos = true;
                break;
            }
        }

        cout << (pos?"YES":"NO") << endl;
        
    }
    return 0;
}