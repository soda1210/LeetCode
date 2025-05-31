#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > 0) break;                         // 提前結束（因為已排序）
      if (i > 0 && nums[i] == nums[i - 1]) continue;  // 去重

      unordered_set<int> set;
      for (int k = i + 1; k < nums.size(); k++) {
        if (k > i + 2 && nums[k] == nums[k - 1] && nums[k - 1] == nums[k - 2])
          continue;

        int target = 0 - (nums[i] + nums[k]);
        if (set.find(target) != set.end()) {
          result.push_back({nums[i], target, nums[k]});
          set.erase(target);  // 去除重複結果
        } else {
          set.insert(nums[k]);
        }
      }
    }

    return result;
  }
};

// 輔助函數：印出二維 vector
void printVector(vector<vector<int>>& vec) {
  for (auto& triplet : vec) {
    cout << "[";
    for (int i = 0; i < triplet.size(); ++i) {
      cout << triplet[i];
      if (i != triplet.size() - 1) cout << ", ";
    }
    cout << "]\n";
  }
  cout << "---------------------\n";
}

// 主測試程式
int main() {
  Solution sol;

  vector<vector<int>> testCases = {
      {-1, 0, 1, 2, -1, -4},            // 標準測資
      {0, 1, 1},                        // 無解
      {0, 0, 0},                        // 特殊：全部為0
      {-2, 0, 1, 1, 2},                 // 多解
      {-4, -2, -2, -2, 0, 1, 2, 3, 4},  // 有重複元素
      {},                               // 空陣列
      {1},                              // 少於3個元素
      {-1, -1, -1, 2, 2, 0}             // 測試負數與正數混合
  };

  for (auto& nums : testCases) {
    cout << "Input: ";
    for (int n : nums) cout << n << " ";
    cout << "\nResult:\n";
    vector<vector<int>> res = sol.threeSum(nums);
    printVector(res);
  }

  return 0;
}
