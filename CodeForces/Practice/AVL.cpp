#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

struct FBT {
    vector<char> arr;
    //2*p + 1 is left child
    //2*p+2 is right child
    //p = 0 is root
    FBT(int size){ 
        int elems = 1;
        while(elems < size){
            elems = (elems << 1);
        }
        arr.resize(elems, 0);
    }

    void insertArr(const vector<char>& nodes){
        queue<int> Q;
        int itr = 0;
        int curr = 0; //root
        Q.push(curr);
        while(curr < log2(arr.size())){
            int size = Q.size();
            for(int i = 0; i<size; i++){
                int pos = Q.front(); Q.pop();
                arr[pos] = nodes[itr++];
                Q.push(2*pos + 1);
                Q.push(2*pos + 2);
            }
            curr++;
        }
    }

    int height(int rootidx){
        if(rootidx > arr.size() || arr[rootidx] == 0){ //base case
            return 0;
        }

        return 1+max(height(2*rootidx+1), height(2*rootidx+2));
    }

    bool checkAVL(int rootidx = 0){
        if(rootidx > arr.size() || arr[rootidx] == 0){ //base case
            return true;
        }

        int leftH = height(2*rootidx+1), rightH = height(2*rootidx + 2);
        if(abs(leftH - rightH) > 1){
            return false;
        }
        return checkAVL(2*rootidx+1) && checkAVL(2*rootidx + 2);
    }
};

int main(){
    FBT fbt(7);
    fbt.insertArr({'A', 'R', 'P', 'I', 'T', 'J', 'A'});
    cout << "is Tree AVL " << fbt.checkAVL() << endl;
    return 0;
}