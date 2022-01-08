#include <iostream>
#include <vector>
using namespace std;

struct UnionFind{
    vector<int> arr;
    int nodes;

    UnionFind(int nodes){
        this->nodes = nodes;
        arr.resize(this->nodes, -1);
    }

    int findParent(int node){
        if(node<nodes){
            int index = node;
            while(arr[index] >= 0){
                index = arr[index];
            }
            //compress
            if(arr[node] >= 0)
                arr[node] = index;

            return index;
        }
        return -1;
    }

    bool Union(int elem1, int elem2){
        if(elem1 < nodes && elem2 < nodes){
            //true denotes parents were different
            //false denotes same parents
            int p1 = findParent(elem1);
            int p2 = findParent(elem2);
            if(p1 != p2){
                //weighted union
                if(abs(arr[p1]) >= abs(arr[p2])){
                    int weight2 = arr[p2];
                    arr[p2] = p1;
                    arr[p1] += weight2;
                }
                else{
                    int weight1 = arr[p1];
                    arr[p1] = p2;
                    arr[p2] += weight1;
                }

                return true;
            }
            else{
                return false;
            }
        }
        return false;
    }
};

int main(){
    int n;
    int edges;
    cin >> n >> edges;
    vector<vector<int>> list(edges, vector<int>(2));
    for(int i = 0; i<edges; i++){
        cin >> list[i][0] >> list[i][1];
    }

    //Connected Components in Undirected graph

    /**
     * for every edge (u,v), perform Union(u,v)
     * Count number of negatives in UnionFind->arr;
    */

    UnionFind uf(n);
    for(auto& edge: list){
        uf.Union(edge[0], edge[1]);
    }
    int count = 0;
    for(int i = 0; i<uf.arr.size(); i++){
        if(uf.arr[i] < 0){
            ++count;
        }
    }

    cout << "Number Connected Components are : " << count << endl;

    return 0;
}