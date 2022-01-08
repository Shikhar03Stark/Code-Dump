#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

int main(){
    FASTIO
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    vector<int> que(q);
    for(auto& e : arr){
        cin >> e;
    }
    for(auto& q : que){
        cin >> q;
    }

    unordered_map<int,int> pos;
    set<int> S;
    for(int i = n-1; i>=0; i--){
        pos[arr[i]] = i;
        S.insert(arr[i]);
    }

    auto comp = [&pos](int a, int b){
        return pos[a] >= pos[b];
    };
    priority_queue<int, vector<int>, decltype(comp)> pq(S.begin(), S.end(), comp);

    dev(pq.top());
//    unordered_map<int,bool> touched;
    queue<int> aux;
    for(auto&q : que){
        int p = 0;
        while(!pq.empty() && pq.top() != q){
            aux.push(pq.top());
            pos[pq.top()]++;
            pq.pop();
            ++p;
        }
        cout << pos[q]+1 << " ";
        int temp = pq.top(); pq.pop();
        pos[temp] = 0;
        while(!aux.empty()){
            pq.push(aux.front());
            aux.pop();
        }
        pq.push(temp);
    }
    return 0;
}