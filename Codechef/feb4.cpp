#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;
const int UpperLimit = 1000000+1;
vector<bool> number(UpperLimit+1, true);
vector<int> prefix(UpperLimit, 0);
void genSieve(){
    //Sieve of Era
    for(int i = 2; i*i<=UpperLimit; i++){
        if(number[i] == true){
            //i was prime
            //uncheck all numbers greater than sqaure and multiple of it
            for(int k = i*i; k<UpperLimit; k+=i){
                number[k] = false;
            }
        }
    }

    //gen Prefix
    for(int i = 2; i<=UpperLimit-1; i++){
        if(number[i] == true){
            prefix[i] = prefix[i-1] + 1;
        }
        else{
            prefix[i] = prefix[i-1];
        }
    }
}

bool isPrime(int n){
    if(n == 2 || n == 3) return true;
    if(n % 2 == 0) return false;
    for(int i = 5; i*i<=n; i+=6){
        if(n%i == 0 || n%(i+2) == 0){
            return false;
        }
    }
    return true;
}

int main(){
    FASTIO
    int t;
    //genSieve();
    cin>>t;
    while(t--){
        int x, y;
        cin >> x >> y;
        if(y == 1){
            if(x>2){
                cout << "Divyam" << endl;
            }
            else{
                cout << "Chef" << endl;
            }
            continue;
        }
        cerr << "Constraint 2" << endl;
        //count primes upto x
        bool flag = true;
        int primes = 0;//prefix[x];
        for(int i = 2; i<=x; i++){
            if(isPrime(i)){
                ++primes;
                if(primes > y){
                    cout << "Divyam" << endl;
                    flag = !flag;
                    break;
                }
            }
        }
        if(flag)
            cout << "Chef" << endl;
        
    }
    return 0;
}