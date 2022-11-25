class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size(), MOD = 1e9+7;
        stack<int>left, right;
        vector<int> left_bound(n,0), right_bound(n,0);
        for(int i = 0; i< n; i++){
          while(!left.empty() && arr[left.top()] > arr[i]){
            left.pop();
          }
          if(left.empty()){
            left_bound[i] = i+1;
          }
          else{
            left_bound[i]  = i - left.top();
          }
          left.push(i);
        }
      for(int i = n-1; i >= 0; i--){
          while(!right.empty() && arr[right.top()] >= arr[i]){
            right.pop();
          }
          if(right.empty()){
            right_bound[i] = n-i;
          }
          else{
            right_bound[i]  = right.top()-i;
          }
          right.push(i);
        }
      long long ans = 0;
      for(int i = 0; i<n; i++){
        long long prod = (left_bound[i]*right_bound[i])%MOD;
        prod = (prod*arr[i])%MOD;
        ans = (ans + prod)%MOD;
      }
      return ans;
    }
};