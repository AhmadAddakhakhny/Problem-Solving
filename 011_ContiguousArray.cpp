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