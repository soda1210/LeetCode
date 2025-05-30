
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  bool canConstruct(string ransomNote, string magazine) {
    for (int i = 0; i < magazine.length(); i++) {
      for (int j = 0; j < ransomNote.length(); j++) {
        if (magazine[i] == ransomNote[j]) {
          ransomNote.erase(ransomNote.begin() + j);
          break;
        }
      }
    }

    return ransomNote.empty();
  }
};

void runTest(string ransomNote, string magazine, bool expected) {
  Solution sol;
  bool result = sol.canConstruct(ransomNote, magazine);
  cout << "ransomNote: \"" << ransomNote << "\", magazine: \"" << magazine
       << "\"\n";
  cout << "Expected: " << (expected ? "true" : "false")
       << ", Got: " << (result ? "true" : "false");
  cout << (result == expected ? " ✅" : " ❌") << "\n\n";
}

int main() {
  // 測試資料
  runTest("a", "b", false);
  runTest("aa", "ab", false);
  runTest("aa", "aab", true);
  runTest("", "anything", true);      // 空字串一定可以組出來
  runTest("abc", "cba", true);        // 所有字母都剛好存在
  runTest("aaa", "aaabbb", true);     // 重複字元測試
  runTest("abcd", "abc", false);      // 缺一個字元
  runTest("aabbcc", "abcabc", true);  // 有兩組字母剛好夠用

  return 0;
}
