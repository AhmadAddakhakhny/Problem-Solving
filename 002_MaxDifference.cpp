#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int maximumDifference(vector<int>& nums) {
    // int max = -1;
    // for (int i =0; i < nums.size()-1; i++) {
    //     for (int j =nums.size() -1; j > i; j--) {
    //         if (nums[j] > nums[i]) {
    //             max = std::max(max, (nums[j] - nums[i]));
    //         }
    //     }
    // }

    int max = -1;
    int max_val = nums.back();
    for (int i = nums.size()-2; i >= 0; i--) {
      if (nums[i] < max_val) {
        max = std::max(max, (max_val - nums[i]));
      }
      max_val = std::max(max_val, nums[i]);
    }

    return max;
}

int main(){
    // [2,59,37,57,10,30]
    // [87,68,91,86,58,63,43,98,6,40]
  vector<int> v{87,68,91,86,58,63,43,98,6,40};

  cout << "maximumDifference = " << maximumDifference(v) << "\n";
  return 0;
}
