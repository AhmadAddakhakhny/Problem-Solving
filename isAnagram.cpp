#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t) {
  if(s.size() != t.size()) return false;

  map<char, int> mp;

  for(int i =0; i< s.size() ; i++) {
    mp[s[i]]++;
  }    

  bool res = true;
  for(int i =0; i< s.size() ; i++){
    if(mp.count(t[i])){
      if(mp[t[i]] != 0)
      mp[t[i]]--;
      else return false;
    } else {
      res = false;
      break;
    }
  }
  

  return res;
}

int main(){
  int num = isAnagram("ahmad","amahd");
  cout << num << "\n";

  return 0;
}
