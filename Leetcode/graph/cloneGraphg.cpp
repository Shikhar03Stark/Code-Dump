#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

struct gNode{
    int val;
    vector<gNode*> neighbours;

    gNode(){
        val = 0;
        neighbours = vector<gNode*>();
    }

    gNode(int val){
        this->val = val;
        neighbours = vector<gNode*>();
    }

    gNode(int val, vector<gNode*> _neighbours){
        this->val = val;
        neighbours = _neighbours;
    }
};

int main(){

    int nodes;
    cin>>nodes;
    vector<gNode*> vec(nodes);
    for(int i = 1; i<=nodes; i++){
        vec[i-1] = new gNode(i);
        int n;
        cin >> n;
        for(int j = 0; j<n; j++){
            int val;

        }
    }
    
    return 0;
}