#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
  map<int, bool> freqMp;
  for(const auto &it : nums) {
    if(!freqMp.count(it)) {
      freqMp.insert(std::pair<int,bool>(it, true));
    } else {
      return true;
    }
  }
  return false;
}

int main(){

  vector<int> v1{1,2,3,1};
  vector<int> v2{1,2,3,1};

  cout << "V1 expect Fales == " << containsDuplicate(v1) << std::endl;
  cout << "V2 expect true == " << containsDuplicate(v2) << std::endl;
  return 0;
}
