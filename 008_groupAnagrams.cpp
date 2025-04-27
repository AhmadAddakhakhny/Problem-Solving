#include <iostream>
#include <bits/stdc++.h>
using namespace std;


/* By Sorting */
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    // sort strings
    vector<vector<string>> ret;
    vector<string> strs_sorted;
    map<string, vector<string>> mp;
    
    for (auto it : strs) {
        std::sort(it.begin(), it.end()); // m*nlogn
        strs_sorted.push_back(it);
        
    }

    int i = 0;
    for (const auto &it : strs_sorted) {
        mp[it].push_back(strs[i]); 
        i++;
    }

    for(const auto &it : mp) {
        ret.push_back(it.second);
    }

    return ret;
}

/* Char Frequency */
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> groups;

    for (const string& s : strs) {
        array<int, 26> freq = {};  // Initialize with 0

        for (char c : s) {
            freq[c - 'a']++;
        }

        // Build a unique key from frequency
        string key;
        for (int count : freq) {
            key += to_string(count) + '#'; // '#' as separator
        }

        groups[key].push_back(s);
    }

    // Collect all groups into a result vector
    vector<vector<string>> result;
    for (auto& group : groups) {
        result.push_back(std::move(group.second));
    }
    
    return result;
}

int main() {

    vector<string> s {"eat","tea","tan","ate","nat","bat"};
    // vector<string> s {"",""};
    auto rStr = groupAnagrams(s);

    for(const auto it : rStr) {
        for(const auto ss : it) {
            cout << ss << " ";
        }
    }

    return 0;
}


// g++ main.cpp && ./a.out
