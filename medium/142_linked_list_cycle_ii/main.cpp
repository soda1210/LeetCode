#include <algorithm>
#include <cstring>  // for memset
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<string> commonChars(vector<string>& A) {
    vector<string> result;
    if (A.empty()) return result;

    int hash[26] = {0};
    for (char ch : A[0]) {
      hash[ch - 'a']++;
    }

    int hashOtherStr[26] = {0};
    for (int i = 1; i < A.size(); i++) {
      memset(hashOtherStr, 0, sizeof(hashOtherStr));
      for (char ch : A[i]) {
        hashOtherStr[ch - 'a']++;
      }
      for (int k = 0; k < 26; k++) {
        hash[k] = min(hash[k], hashOtherStr[k]);
      }
    }

    for (int i = 0; i < 26; i++) {
      while (hash[i]-- > 0) {
        result.push_back(string(1, i + 'a'));
      }
    }

    return result;
  }
};

void printResult(const vector<string>& result) {
  cout << "[ ";
  for (const auto& s : result) {
    cout << "\"" << s << "\" ";
  }
  cout << "]" << endl;
}

int main() {
  Solution sol;

  vector<vector<string>> testCases = {
      {"bella", "label", "roller"},  // Output: ["e", "l", "l"]
      {"cool", "lock", "cook"},      // Output: ["c", "o"]
      {"a", "b", "c"},               // Output: []
      {"abc", "abc", "abc"},         // Output: ["a", "b", "c"]
      {"abbb", "bbba", "babb"},      // Output: ["a", "b", "b"]
      {"abcd"},                      // Output: ["a", "b", "c", "d"]
      {"aa", "aaa", "aaaaa"},        // Output: ["a", "a"]
      {"", "", ""},                  // Output: []
      {}                             // Output: []
  };

  for (size_t i = 0; i < testCases.size(); ++i) {
    cout << "Test Case " << i + 1 << ": ";
    vector<string> res = sol.commonChars(testCases[i]);
    printResult(res);
  }

  return 0;
}
