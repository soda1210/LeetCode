#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string reverseWords(string s) {
    int start = 0;
    int end = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == ' ') {
        end = i;
        reverse(&s[start], &s[end]);
        start = i + 1;
      }
    }
    reverse(&s[start], &s[s.size()]);
    return s;
  }
};

int main() {
  Solution sol;

  vector<string> inputs = {"hello", "Let's take LeetCode contest", "", "   ",
                           "  hello  world  "};

  for (const auto& s : inputs) {
    cout << "Input: \"" << s << "\"" << endl;
    cout << "Output: \"" << sol.reverseWords(s) << "\"" << endl << endl;
  }

  return 0;
}
