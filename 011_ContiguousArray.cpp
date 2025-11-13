#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// TODO: Read the below solution

// int findMaxLength(vector<int>& nums) {
//        int sum=0;
//        unordered_map<int,int> m;
//        unsigned int longestContArray = 0;
       
//         for(int i=0;i<nums.size();i++){
//            sum += (nums[i]==0)?-1:1;
           
//            auto it = m.find(sum);
           
//            if(sum == 0){
//               if(longestContArray < i+1)
//                longestContArray = i+1;
//            }
//            else if(it != m.end()){
//               if(longestContArray < i-it->second)
//                longestContArray = i-it->second;
//            }
//            else if(it == m.end())
//                 m.insert({sum,i});
//        }
//         return longestContArray;
//     }

int findMaxLength(vector<int>& nums) {
    int ones = 0;
    int zeros = 0;
    int res = 0;
    unordered_map<int, int> mp; // difference to index

    for(int i = 0; i < nums.size(); i++) {

        (nums[i]) ? ones++ : zeros++;
        int diff  = ones - zeros;
        
        // don't overwrite the existed diff-index to ensure having the longest subarray
        if (!mp.count(diff)) {
            mp[diff] = i;
        }
        
        if (ones == zeros){
            res = std::max(res, (ones + zeros));
        }
        else {
            res = std::max(res, (i - mp[diff]));
        }
    }

    return res;
}

int main () {

    vector<int> nums{0,1,1,1,1,1,0,0,0};
    // vector<int> nums{1,1,1,0,0,0};
    // Output: 6
    cout << "Is output == 6? ans =  " << findMaxLength(nums) << std::endl;
    return 0;
}


// int getLongestOnes(const vector<int> &nums, const int k) {
//   int length = 0;
  
//   for (int start = 0; start < nums.size();start++) {
//     int cntr = 0;
//     int current_length = 0;
//     for (int end = start; end < nums.size(); end++) {

//       if (nums.at(end) == 0) {
//         if (cntr < k) {
//           cntr++;
//         } else {
//           break;
//         }
//       }

//       current_length++;
//       length = std::max(length, current_length);
//     }
//   }

//   return length;
// }

int getLongestOnes(const vector<int> &nums, const int k) {
  int length = 0;
  int cntr = 0;
  int current_length = 0;
  
  for (int start = 0, end = 0; end < nums.size();) {
    
    if (nums.at(end) == 0) {
      if (cntr < k) {
        cntr++;
        current_length = end - start + 1;
        end++;
      } else {
        // sherink
        // adjust length?
        while(cntr >= k) {
          if (nums.at(start) == 1) {
            start++;
          } else {
            start++;
            cntr--;
            current_length = end - start + 1;
          }
        }
       
      }
    } else {
      current_length = end - start + 1;
      end++;
    }

    length = std::max(length, current_length);
  }

  return length;
}

int main(){
  // vector<int> nums = {0,0,0,0,1,1,1,0}; //-> 5
  // vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0}; // ->6
  // vector<int> nums = {0,0,0,0,0}; //-> 2
  vector<int> nums = {1,1,1,1,1}; //-> 5


  int k = 2;

  int length = getLongestOnes(nums, k);

  cout << "length: " << length << endl;
  
  return 0;
}