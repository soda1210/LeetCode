#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> hash;
    int max_len = 0;
    int start = 0;

    for (int end = 0; end < s.size(); end++) {
      char c = s[end];
      if (hash.count(c)) {
        start = max(start, hash[c] + 1);
      }
      hash[c] = end;
      max_len = max(max_len, end - start + 1);
    }

    return max_len;
  }
};
