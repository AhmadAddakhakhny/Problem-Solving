#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int getSum(vector<int>& nums, int idx, int sz) {

  int sum = 0;
  while (sz && sz--) {
    sum += nums[idx++];
  }

  return sum;
}
int subarraySum(vector<int>& nums, int k) {
    int cntr = 0;
        for (int window =1; window <= nums.size(); window++) {
          for (int cur = 0; (cur+window) <= nums.size(); cur ++) {
            if(getSum(nums, cur, window) == k) {
              cntr++;
            }
          }
        }
    return cntr;
}

int main(){
  // [1,1,1], k = 2
  // [1,2,3], k = 3
  // [1,2,3,1,2,3,1,2,3,1,2,3,1,2,3]
  vector<int> nums{1,2,3};
  int k = 3;
  int num = subarraySum(nums,k);
  cout << num << "\n";

  return 0;
}



// int subarraySum(vector<int>& nums, int k) {

//     int freq = 0, sum = 0;
//     unordered_map<int,int> prefix_sum;
//     prefix_sum[0] = 1;
    
//     for (int i = 0; i < nums.size(); i++) {

//         sum += nums[i];
        
//         if (prefix_sum.count(sum - k)){
//             freq += prefix_sum[sum - k];
//         }

//         ++prefix_sum[sum];
//     }

//     return freq;
// }

// int main() {

//     vector<int> v{1,1,1};
//     int k = 2;
//     // vector<int> v{1,2,3};
//     // int k = 3;

//     std::cout << "Total No. of Subarrays: " << subarraySum(v,k) << endl;

//     return 0;
// }
