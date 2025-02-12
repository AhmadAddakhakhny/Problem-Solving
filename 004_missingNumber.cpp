#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int missingNumber(vector<int>& nums) {
  int sum = nums.size();

  /* this technique prevents overflow for large numbers summation */
  for (int idx = 0; idx < nums.size(); idx++) {
    sum += idx - nums[idx];
  }
  
  return sum;
}
// int missingNumber(vector<int>& nums) {
//   int sz = nums.size();
//   int great_sum = (sz*(sz+1)) / 2;
//   int total = 0;
//   for(auto it : nums) {
//     total += it;
//   }

//   int sub = great_sum - total;

//   return sub;
// }

// int missingNumber(vector<int>& nums) {
//   int res = nums.size();

//   for (int idx = 0; idx < nums.size(); idx++) {
//     res ^= idx ^ nums[idx];
//   }
  
//   return res;
// }

int main(){
  vector<int> v{0,1,2};
  int num = missingNumber(v);
  cout << num << "\n";

  return 0;
}
