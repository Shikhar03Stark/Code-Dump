#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Queue{
    stack<T> S1, S2;
    int size;
    public:
    Queue(){
        size = 0;
    }
    void enque(T x){
        S1.push(x);
        size++;
    }

    T deque(){
        if(size>0){
            if(S2.empty()){
                while(!S1.empty()){
                    S2.push(S1.top()); S1.pop();
                }
            }
            T val = S2.top(); S2.pop();
            size--;
            return val;
        }
        else{
            cerr << "Queue EMPTY\n";
            return T();
        }
    }

    int getSize(){
        return this->size;
    }

};

int main(){
    Queue<char> q;
    vector<char> ops = {'a', 'b', 1, 'c', 1, 0, 'd', 0, 1, 1, 0 , 1};
    for(auto& op: ops){
        if(op==0){
            cout << "SIZE: " << q.getSize() << endl;
        }
        else if(op==1){
            char val = q.deque();
            cout << "FRONT: " <<  val << endl;
        }
        else{
            cout << "PUSHED: " << op << endl;
            q.enque(op);
        }
    }
    return 0;
}