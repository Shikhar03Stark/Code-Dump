#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

void genPrime(vector<ull>& primes, int size){
    ull start = 2;
    while(primes.size()<size){
        if(start == 2 || start == 3){
            primes.push_back(start);
        }
        else{
            bool prime = true;
            for(int i = 2; i*i<=start; i++){
                if(start%i == 0){
                    prime = false;
                    break;
                }
            }
            if(prime){
                primes.push_back(start);
            }
        }
        ++start;
    }
}

int main(){
    int t;
    cin>>t;
    vector<ull> primeList;
    genPrime(primeList, 100000);
    for(int z = 1; z<=t; z++){
        cout << "Case #" << z << ": ";
        //cout << primeList.size() << endl;
        ull n;
        cin >> n;

        int index = lower_bound(primeList.begin(), primeList.end(), ceil(sqrt(n))) - primeList.begin();
        //dev(primeList[index-1]);
        if(primeList[index]*primeList[index-1] > n){
           index = index-1;
        }
        cout << (ull)primeList[index]*primeList[index-1] << endl;
    }
    return 0;
}