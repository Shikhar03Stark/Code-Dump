#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

ull longSub(vector<ull> &cards){
    ull n = cards.size();
    ull prev = 0;
    ull cnt = 0;
    for(ull i = 0; i<n; i++){
        if(cards[i] > prev){
            prev = cards[i];
            cnt++;
        }
    }
    return cnt;
}

int main(){
    int t;
    cin>>t;
    for(int z = 1; z<=t; z++){
        cout << "Case #" << z << ": ";
        ull n;
        cin >> n;
        vector<ull> cards;
        for(ull i = 0; i<n; i++){
            cards.push_back(i+1);
        }
        ull cnt = 0;
        ull perms = 0;
        do{
            cnt += longSub(cards);
            perms++;
        }while(next_permutation(begin(cards), end(cards)));
        cout.precision(12);
        cout << (double)(cnt)/perms << endl;

    }
    return 0;
}