#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<uint> A(n),B(m);
        priority_queue<uint, vector<uint>, greater<uint>> Abank;
        priority_queue<uint> Bbank;
        unsigned ll votesA = 0, votesB = 0;
        for(int i = 0; i<n; i++){
            cin >> A[i];
            Abank.push(A[i]);
            votesA += A[i];
        }
        for(int i = 0; i<m; i++){
            cin >> B[i];
            Bbank.push(B[i]);
            votesB += B[i];
        }

        if(votesA == votesB && Abank.top() == Bbank.top()){
            cout << -1 << endl;
            continue;
        }
        if(votesA > votesB){
            cout << 0 << endl;
            continue;
        }
        int swaps = 0;
        while(votesA < votesB && swaps <= max(A.size(), B.size())){
            int minA = Abank.top();
            Abank.pop();
            int maxB = Bbank.top();
            Bbank.pop();

            Abank.push(maxB);
            Bbank.push(minA);

            votesA = votesA - minA + maxB;
            votesB = votesB + minA - maxB;
            swaps++;
        }
        if(votesA < votesB){
            cout << swaps << endl;
        }
        else{
            cout << -1 << endl;
        }



    }
    return 0;
}