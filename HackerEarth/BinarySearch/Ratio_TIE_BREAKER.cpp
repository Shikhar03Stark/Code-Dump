#include<bits/stdc++.h>
using namespace std;

bool isgreater(vector<vector<double>> &arr, double K, double x){
    double sum = 0;
    for(int i = 0; i<arr.size(); i++){
        sum += arr[i][0]/(arr[i][1] + x);
    }

    if(sum >= K){
        return true;
    }
    return false;

}

bool iseq(vector<vector<double>> &arr, double K, double x){
    double sum = 0;
    for(int i = 0; i<arr.size(); i++){
        sum += arr[i][0]/(arr[i][1] + x);
    }
    cerr << abs(K-sum) << endl;
    if(abs(K-sum) <= 1e-9){
        return true;
    }
    return false;

}

double solve (vector<vector<double> > arr, double K) {
   // Write your code here
   int max_a = 0, min_b = 0;
   for(int i = 0; i<arr.size(); i++){
       if(arr[max_a][0] < arr[i][0]){
           max_a = i;
       }
       if(arr[min_b][1] > arr[i][1]){
           min_b = i;
       }
   }

   double low = -arr[min_b][1]-1e-7, high = arr[max_a][0];
   while(low<=high){
       double mid = (low+high)/2;
       if(isgreater(arr, K, mid)){
           low = mid+1e-7;
       }
       else{
           high = mid-1e-7;
       }
   }
   //cout << low << endl;

   return high;

}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int col;
    cin >> col;
    vector<vector<double> > arr(N, vector<double>(col));
    for (int i_arr=0; i_arr<N; i_arr++)
    {
    	for(int j_arr=0; j_arr<col; j_arr++)
    	{
    		cin >> arr[i_arr][j_arr];
    	}
    }
    double K;
    cin >> K;

    double out_;
    out_ = solve(arr, K);
    cout << out_;
}