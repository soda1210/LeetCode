#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  string reverseStr(string s, int k) {
    for (int idx = 0; idx < s.size(); idx += (2 * k)) {
      if (idx + k > s.size()) {
        reverse(s.begin() + idx, s.end());
      } else {
        reverse(s.begin() + idx, s.begin() + idx + k);
      }
    }
    return s;
  }
};

int main() {
  Solution sol;
  vector<pair<string, int>> tests = {
      make_pair("abcdefg", 2),    // bacdfeg
      make_pair("abcd", 4),       // dcba
      make_pair("abcdefghi", 3),  // cbadefihg
      make_pair("a", 2),          // a
      make_pair("ab", 1),         // ab
      make_pair("ab", 3),         // ba
      make_pair("", 2),           // ""
      make_pair("abcdef", 2),     // bacdfe
      make_pair("abcdef", 3),     // cbadef
  };

  for (size_t i = 0; i < tests.size(); ++i) {
    string s = tests[i].first;
    int k = tests[i].second;
    cout << "Input: \"" << s << "\", k = " << k << "\n";
    cout << "Output: \"" << sol.reverseStr(s, k) << "\"\n\n";
  }

  return 0;
}
