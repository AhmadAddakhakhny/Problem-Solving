#include <iostream>
#include<bits/stdc++.h>
using namespace std;
// LINK: https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

int lengthOfLongestSubstring(string str) {
  int length = 0;
  unordered_map<char, bool> mp_Char2Cntr;
  
  for (int start = 0, end = 0; end < str.size();) {
    int curr_length = 0;

    if (!mp_Char2Cntr.count(str[end])) {
      mp_Char2Cntr[str[end]] = true;
      curr_length = end - start + 1;
      end++;
    } else {
      while(mp_Char2Cntr.count(str[end])) {
        mp_Char2Cntr.erase(str[end]);
        start++;
      }
      curr_length = end - start + 1;
    }
    length = std::max(curr_length, length);
  }

  return length;
}

int main(){
  string str = "pwwkew";
  cout << "length: " << lengthOfLongestSubstring(str) << endl;
  
  return 0;
}
