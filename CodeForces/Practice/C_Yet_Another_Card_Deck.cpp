#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

int main(){
        int n, q;
        cin >> n >> q;
        vector<int> arr(n+1);
        vector<int> qu(q);
        for(int i = 1; i<=n; i++){
            cin >> arr[i];
        }
        for(auto& e: qu){
            cin >> e;
        }

        unordered_map<int,int> pos;
        set<int> S;
        for(int i = n; i>0; i--){
            pos[arr[i]] = i;
            S.insert(arr[i]);
        }

        auto comp = [&pos](int a, int b)->bool{
            return pos[a] < pos[b];
        };

        priority_queue<int, vector<int>, decltype(comp)> pq(comp);
        for(auto& e: S){
            pq.push(e);
        }

        for(auto& q: qu){
            stack<int> S;
            while(q != pq.top()){
                S.push(pq.top());
                pq.pop();
            }
            cout << pos[q] << ' ';
            while(!S.empty()){
                pos[S.top()]++;
                pq.push(S.top());
                S.pop();
            }
        }

        cout << endl;


    return 0;
}