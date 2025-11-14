#include <iostream>
#include<bits/stdc++.h>
using namespace std;


int getMaxSubArray(vector<int>& nums) {
  
  if (nums.size() == 0) return 0;

  int maxSum = INT_MIN;
  int currSum = 0;

  for (int start = 0, end = 0; end < nums.size();) {
    if (currSum >= 0) {
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

int getMinSubArray(vector<int>& nums) {
  
  if (nums.size() == 0) return 0;

  int minSum = INT_MAX;
  int currSum = 0;

  for (int start = 0, end = 0; end < nums.size();) {
    if (currSum <= 0) {
      currSum += nums.at(end);
      end++;
      minSum = std::min(minSum, currSum);
    } else { // reset the starting side
      start = end;
      currSum = 0;
    }
  }

  return minSum;
}

int maxAbsoluteSum(vector<int>& nums) {

  int minSum = getMinSubArray(nums);
  minSum = (minSum < 0) ? -minSum : minSum;
  int maxSum = getMaxSubArray(nums);
  int max = std::max(minSum, maxSum);

  return max;
    
}

int main(){
  vector<int> nums {2,-5,1,-4,3,-2}; // o/p = 8
  cout << maxAbsoluteSum(nums) << endl;
  
  return 0;
}
