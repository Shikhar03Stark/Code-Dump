#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        vector<int> primes;
        //scan for next n primes
        int i = 2;
        while(primes.size() < n){
            if(i == 2){
                primes.push_back(i);
                i++;
                continue;
            }
            bool isPrime = true;
            for(int j = 2; j*j <= i; j++){
                if(i%j == 0){
                    isPrime = false;
                    break;
                }
            }
            if(isPrime){
                primes.push_back(i);
            }
            ++i;
        }
        vector<ll> A(n,1);
        vector<ll> B(n,1);
        for(auto &e: B){
            cin >> e;
        }

        for(int i = 0;i<n;i++){
            if(B[i] != (i+1)){
                primes[i] = primes[B[i]-1];
            }
        }

        for(auto &p : primes){
            cout << p << " ";
        }
        cout << endl;

        /*
        vector<vector<int> > numSpace(n);

        for(int i = 0;i<n;i++){
            numSpace[B[i] - 1].push_back(i);
        }
        int p_index = 0;
        for(auto &vec: numSpace){
            for(int i = 0; i<vec.size(); i++){
                if (i == 0){
                    A[vec[i]] = primes[p_index];
                }
                else{
                    A[vec[i]] = A[vec[i-1]]*primes[p_index];
                }

            }
            if(vec.size() > 0){
                ++p_index;
            }
        }

        for(auto &e: A){
            cout << e << " ";
        }
        cout << endl;
        */
    }
    return 0;
}