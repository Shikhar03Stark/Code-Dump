#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;
void findMedian(int *arr, int n) {
    // Write your code here
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    max_heap.push(arr[0]);
    cout << arr[0] << " ";
    for(int i = 1; i < n; i++){
        int median = 0;
        if(arr[i] <= max_heap.top()){
                max_heap.push(arr[i]);
            }
        else{
            min_heap.push(arr[i]);
        }
        if(max_heap.size()-min_heap.size() > 1){
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        else if(min_heap.size()-max_heap.size() > 1){
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
        
        if(max_heap.size() > min_heap.size()){
            median = max_heap.top();
        }
        else if(max_heap.size() < min_heap.size()){
            median = min_heap.top();
        }
        else{
            median = (max_heap.top() + min_heap.top())/2;
        }
        cout << median << " ";
    }
}

int main(){
    int arr[] = {6, 2, 1, 3, 7, 5};
    findMedian(arr, sizeof(arr)/(sizeof(int)));
    return 0;
}