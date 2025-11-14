#include <iostream>
#include<bits/stdc++.h>
using namespace std;


int maxSubArray(vector<int>& nums) {
  
  if (nums.size() == 0) return 0;

  int maxSum = INT_MIN;
  int currSum = 0;

  for (int start = 0, end = 0; end < nums.size();) {
    if (currSum >= 0) { // expand the ending side
      currSum += nums.at(end);
      end++;
      maxSum = std::max(maxSum, currSum);
    } else { // reset the starting side
      start = end;
      currSum = 0;
    }
  }

  return maxSum;
}

int main(){
  vector<int> nums {-2,1,-3,4,-1,2,1,-5,4}; // o/p = 6
  cout << "length: " << maxSubArray(nums) << endl;
  
  return 0;
}
