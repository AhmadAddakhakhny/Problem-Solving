#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>& nums) {
  int sz = nums.size();
  int great_sum = (sz*(sz+1)) / 2;
  int total = 0;
  for(auto it : nums) {
    total += it;
  }

  int sub = great_sum - total;

  return sub;
}

int main(){
  vector<int> v{0,1,2};
  int num = missingNumber(v);
  cout << num << "\n";

  return 0;
}
