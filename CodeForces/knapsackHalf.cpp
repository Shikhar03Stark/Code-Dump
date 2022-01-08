#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

bool solve(vector<int>& w, int b, int sum, int index, stack<int>& s){
    if(sum >= ceil(b/2) && sum <= b){
        return true;
    }
    if(index >= w.size()){
        return false;
    }
    s.push(index);
    bool pick = solve(w, b, sum+w[index], index+1, s);
    if(pick){
        return true;
    }
    s.pop();
    bool npick = solve(w,b, sum, index+1, s);
    if(npick){
        return true;
    }
    return false;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, b;
        cin >> n >> b;
        vector<pair<int,int>> w(n);
        int index = 1;
        for(auto& p: w){
            cin >> p.first;
            p.second = index++;
        }

        int sum = 0;
        vector<int> in;
        for(int i = 0; i<w.size(); i++){
            pair<int,int> p = w[i];
            if(p.first > b){
                continue;
            }
            if(p.first >= ceil((float)b/2) && p.first <= b){
                sum = p.first;
                in.clear();
                in.push_back(p.second);
                break;
            }
            sum += p.first;
            in.push_back(p.second);
            if(sum >= ceil((float)b/2) && sum <= b){
                break;
            }
        }

        if(sum >= ceil((float)b/2) && sum <= b){
            cout << in.size() << endl;
            for(auto& i : in){
                cout << i << " ";
            }
            cout << endl;
        }
        else{
            cout << -1 << endl;
        }
        
    }
    return 0;
}