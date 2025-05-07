#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int maximumWealth(vector<vector<int>>& accounts) {
    int ans = 0;
    for (vector<int> list : accounts) {
      int sum = 0;
      for (int temp : list) {
        sum += temp;
      }
      ans = (sum > ans) ? sum : ans;
    }
    return ans;
  }
};

int main() {
  Solution sol;

  vector<vector<vector<int>>> testCases = {
      {{1, 2, 3}, {3, 2, 1}},             // output: 6
      {{1, 5}, {7, 3}, {3, 5}},           // output: 10
      {{2, 8, 7}, {7, 1, 3}, {1, 9, 5}},  // output: 17
      {{5}},                              // output: 5
      {{1, 1, 1, 1}, {0, 0, 0, 10}},      // output: 10
      {{1000, 2000, 3000}, {1, 2, 3}},    // output: 6000
      {{0, 0, 0}, {0, 0, 1}},             // output: 1
      {{}}                                // output: 0 (空的顧客）
  };

  for (auto& test : testCases) {
    cout << "Max wealth: " << sol.maximumWealth(test) << endl;
  }

  return 0;
}
