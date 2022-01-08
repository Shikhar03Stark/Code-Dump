#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

vector<bool> prime(3001, true);
vector<int> p;
void genPrime(){
    for(int i = 2; i*i <= 3000; i++){
        if(prime[i] == true){

            for(int j = i*i; j<=3000; j += i){
                prime[j] = false;
            }
        }
    }

    for(int i = 2; i<=3000; i++){
        if(prime[i] == true) p.push_back(i);
    }
}

int main(){
    int t;
    cin>>t;
    genPrime();
    while(t--){
        int x, y;
        cin >> x >> y;
        int tot = x+y;
        for(int i = 0; i<100; i++){
            cerr << p[i] << " ";
        }
        cerr << endl;
        if(prime[tot] == true){
            cout << *lower_bound(p.begin(), p.end(), tot+1) - (tot) << endl;
        }
        else{
            cout << *lower_bound(p.begin(), p.end(), tot) - (tot) << endl;
        }
    }
    return 0;
}